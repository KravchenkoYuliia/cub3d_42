Absolutely. Let's build **both** features for your `Cub3D` project:

---

# ✅ Part 1: **Textured Floor and Ceiling Casting**

This adds **real texture mapping** to floors and ceilings — just like Wolfenstein 3D and DOOM.

---

## 🎯 Goal

For every screen column **below** and **above** the wall:

* Compute **which point on the floor/ceiling** it corresponds to
* Fetch the right pixel from the **floor/ceiling texture**
* Draw it

---

## 🧱 Required Data

Update your `t_game` to store floor/ceiling textures:

```c
typedef struct s_game
{
	// ...
	t_img	texture[6]; // 0-3: walls, 4 = floor, 5 = ceiling
}	t_game;
```

Then load them (in `init_textures()`):

```c
	load_texture(mlx, &game->texture[4], "textures/floor.xpm");
	load_texture(mlx, &game->texture[5], "textures/ceiling.xpm");
```

---

## ✏️ Add to `render_column()` (After Wall Drawing)

Below is the **textured floor/ceiling casting loop** (drop-in ready):

```c
void	render_textured_floor_and_ceiling(t_game *game,
	t_raycasting *rc, int x, int draw_end)
{
	int		y;
	double	row_dist;
	double	floor_x;
	double	floor_y;
	double	weight;
	int		floor_tex_x;
	int		floor_tex_y;
	t_img	*floor_tex = &game->texture[4];
	t_img	*ceil_tex = &game->texture[5];

	y = draw_end + 1;
	while (y < game->screen_height)
	{
		row_dist = (double)game->screen_height / (2.0 * y - game->screen_height);
		weight = row_dist / rc->wall_dist;

		if (rc->side_hit == 0)
		{
			floor_x = rc->map_x + (rc->ray_dir_x > 0 ? 1 : 0);
			floor_y = rc->map_y + rc->wall_x;
		}
		else
		{
			floor_x = rc->map_x + rc->wall_x;
			floor_y = rc->map_y + (rc->ray_dir_y > 0 ? 1 : 0);
		}

		floor_x = weight * floor_x + (1.0 - weight) * game->player.pos_x;
		floor_y = weight * floor_y + (1.0 - weight) * game->player.pos_y;

		floor_tex_x = (int)(floor_x * floor_tex->width) % floor_tex->width;
		floor_tex_y = (int)(floor_y * floor_tex->height) % floor_tex->height;

		int floor_color = *(int *)(floor_tex->addr + floor_tex_y * floor_tex->line_length
				+ floor_tex_x * (floor_tex->bpp / 8));
		int ceil_color = *(int *)(ceil_tex->addr + floor_tex_y * ceil_tex->line_length
				+ floor_tex_x * (ceil_tex->bpp / 8));

		put_pixel_to_image(&game->img, x, y, floor_color);
		put_pixel_to_image(&game->img, x, game->screen_height - y, ceil_color);
		y++;
	}
}
```

---

## 💡 Call it in `render_column()`

At the end of your existing `render_column()`:

```c
render_textured_floor_and_ceiling(game, rc, x, draw_end);
```

---

## ✅ Floor/Ceiling Casting Summary

| Element         | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| `row_dist`      | Distance from player to current row (based on screen height) |
| `weight`        | Interpolation weight between player and wall hit             |
| `floor_x/y`     | Real-world floor position being rendered                     |
| `floor_tex_x/y` | Texture coordinates used to sample floor/ceiling textures    |

Now your floors and ceilings will be **mapped and dynamic**, not just colored.

---

# ✅ Part 2: **Player Movement & Collision Detection**

Let’s now implement basic **player movement (WASD)** and **collision against walls**.

---

## 🧱 Add to `t_player`

```c
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;
```

---

## 🧭 Movement System (WASD)

```c
#define MOVE_SPEED 0.08
#define ROT_SPEED 0.05

void	move_player(t_game *game, int keycode)
{
	t_player	*pl = &game->player;
	char		**map = game->map;
	double		new_x, new_y;

	if (keycode == KEY_W)
	{
		new_x = pl->pos_x + pl->dir_x * MOVE_SPEED;
		new_y = pl->pos_y + pl->dir_y * MOVE_SPEED;
		if (map[(int)pl->pos_y][(int)new_x] != '1')
			pl->pos_x = new_x;
		if (map[(int)new_y][(int)pl->pos_x] != '1')
			pl->pos_y = new_y;
	}
	if (keycode == KEY_S)
	{
		new_x = pl->pos_x - pl->dir_x * MOVE_SPEED;
		new_y = pl->pos_y - pl->dir_y * MOVE_SPEED;
		if (map[(int)pl->pos_y][(int)new_x] != '1')
			pl->pos_x = new_x;
		if (map[(int)new_y][(int)pl->pos_x] != '1')
			pl->pos_y = new_y;
	}
	if (keycode == KEY_A)
	{
		new_x = pl->pos_x - pl->plane_x * MOVE_SPEED;
		new_y = pl->pos_y - pl->plane_y * MOVE_SPEED;
		if (map[(int)pl->pos_y][(int)new_x] != '1')
			pl->pos_x = new_x;
		if (map[(int)new_y][(int)pl->pos_x] != '1')
			pl->pos_y = new_y;
	}
	if (keycode == KEY_D)
	{
		new_x = pl->pos_x + pl->plane_x * MOVE_SPEED;
		new_y = pl->pos_y + pl->plane_y * MOVE_SPEED;
		if (map[(int)pl->pos_y][(int)new_x] != '1')
			pl->pos_x = new_x;
		if (map[(int)new_y][(int)pl->pos_x] != '1')
			pl->pos_y = new_y;
	}
}
```

---

## 🔁 Rotation System (LEFT/RIGHT)

```c
void	rotate_player(t_player *pl, int keycode)
{
	double	old_dir_x = pl->dir_x;
	double	old_plane_x = pl->plane_x;
	double	angle = (keycode == KEY_LEFT) ? -ROT_SPEED : ROT_SPEED;

	pl->dir_x = pl->dir_x * cos(angle) - pl->dir_y * sin(angle);
	pl->dir_y = old_dir_x * sin(angle) + pl->dir_y * cos(angle);
	pl->plane_x = pl->plane_x * cos(angle) - pl->plane_y * sin(angle);
	pl->plane_y = old_plane_x * sin(angle) + pl->plane_y * cos(angle);
}
```

---

## 🧠 Hook it into Your Key Handling

In your key press handler:

```c
int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		move_player(game, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_player(&game->player, keycode);

	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}
```

---

## ✅ Summary

| Feature                               | Description                                        |
| ------------------------------------- | -------------------------------------------------- |
| `render_textured_floor_and_ceiling()` | Floor/ceiling texture mapping with real projection |
| `move_player()`                       | WASD movement with wall collision                  |
| `rotate_player()`                     | Left/right rotation (camera turning)               |
| Integrated in key handler             | `handle_key()` updates player state + re-renders   |

---

## ✅ Want to go further?

Here’s what I can help with next:

* 🌍 **Map file parser** (.cub format)
* 🧭 **Minimap rendering**
* 🔊 **Footstep sounds or basic audio**
* 💡 **Lighting / fog / distance shading**
* 💥 **Doors or interactive walls**
* 🐞 **Debugging DDA or ray collision issues**

Let me know what you'd like to add next!
