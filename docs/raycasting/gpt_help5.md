Absolutely — let's walk through **all 3 upgrades** so your **Cub3D raycasting engine** is complete and polished with:

1. ✅ **Loading XPM textures** into `t_img`
2. ✅ **Parsing wall directions** for texture selection
3. ✅ **Optional: Floor and ceiling casting** (for realism beyond just flat colors)

---

# ✅ 1. Loading XPM Textures into `t_img`

### 🧱 Your `t_img` Struct

```c
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;
```

---

### 🔧 Load a Single Texture

```c
void	load_texture(void *mlx, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img_ptr)
	{
		ft_putstr_fd("Error: Failed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bpp, &tex->line_length, &tex->endian);
}
```

> You can call this for each wall direction in `init_textures()`:

---

### 🚀 Init All Textures

```c
void	init_textures(t_game *game, void *mlx)
{
	load_texture(mlx, &game->texture[0], "textures/wall_north.xpm");
	load_texture(mlx, &game->texture[1], "textures/wall_south.xpm");
	load_texture(mlx, &game->texture[2], "textures/wall_west.xpm");
	load_texture(mlx, &game->texture[3], "textures/wall_east.xpm");
}
```

---

# ✅ 2. Parsing Wall Directions from Map

To choose the correct texture per wall direction, you need to:

* Know what side the wall is on (already done via `side_hit`)
* Know the direction the ray came from

---

### 🧠 Direction-Based Texture Index

```c
// returns: 0 = north, 1 = south, 2 = west, 3 = east
int	get_texture_index(t_raycasting *rc)
{
	if (rc->side_hit == 0)
		return (rc->ray_dir_x < 0) ? 3 : 2; // X-side: west (3) or east (2)
	else
		return (rc->ray_dir_y < 0) ? 1 : 0; // Y-side: north (1) or south (0)
}
```

> You can tweak the index-to-texture mapping as needed — just be consistent.

---

## ✅ 3. Optional: Floor and Ceiling Casting (Bonus)

If you want **realistic floors and ceilings** (instead of solid color fill), you'll cast rays to the floor the same way you do for walls — but only for the lower half of the screen.

For simplicity, here's a **"floor-casting approximation"** — fast and good-looking.

---

### ✨ Floor Casting in `render_column()`

Add this **after drawing the wall**, inside `render_column()`:

```c
void	render_floor_and_ceiling(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < game->screen_height)
	{
		put_pixel_to_image(&game->img, x, y, FLOOR_COLOR);
		put_pixel_to_image(&game->img, x, game->screen_height - y, CEIL_COLOR);
		y++;
	}
}
```

And in `render_column()` (after wall drawing):

```c
render_floor_and_ceiling(game, x, draw_end);
```

> This draws the floor from the bottom of the wall to the bottom of the screen, and the ceiling symmetrically from top.

---

### 🧠 For Real Floor Mapping (Advanced)

For full texture-mapped floor/ceiling (like DOOM), you’d:

* Calculate exact position on floor based on camera + wall hit
* Interpolate floor texture coordinates per pixel
* Sample floor/ceiling textures

Let me know if you want the **full floor-texture algorithm** — but many 42 projects just go with the above approximation.

---

## 🧩 How it All Comes Together

### Example Game Init

```c
int	main(void)
{
	t_game	game;

	init_game_struct(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
	game.img.img_ptr = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.img.addr = mlx_get_data_addr(game.img.img_ptr,
		&game.img.bpp, &game.img.line_length, &game.img.endian);
	init_textures(&game, game.mlx);
	game_loop(&game);
	return (0);
}
```

---

### Example Raycasting Pipeline

```c
void	cast_rays(t_game *game)
{
	int				x;
	t_raycasting	rc;

	x = 0;
	while (x < game->screen_width)
	{
		init_raycast(&rc, &game->player, x, game->screen_width);
		calc_step_and_side_dist(&rc, &game->player);
		perform_dda(&rc, game->map);
		compute_wall_dist(&rc, &game->player);
		render_column(game, &rc, x);
		x++;
	}
}
```

---

## ✅ Summary of New Features

| Feature               | ✅ Implemented? | Description                                         |
| --------------------- | -------------- | --------------------------------------------------- |
| Load XPM textures     | ✅              | Using `mlx_xpm_file_to_image()`                     |
| Texture-mapped walls  | ✅              | Direction-based textures sampled in `render_column` |
| Texture indexing      | ✅              | Wall side & ray dir → correct texture               |
| Flat floor/ceiling    | ✅              | Clean look with colored halves                      |
| Floor/ceiling casting | 🕓 Optional    | Can be added later for full realism                 |

---

Would you like me to:

* Add **textured floor/ceiling casting**?
* Help with **player movement/collision**?
* Explain **map parsing** for `.cub` files?
* Integrate a **minimap** for debugging?

Let me know what you’re building next!
