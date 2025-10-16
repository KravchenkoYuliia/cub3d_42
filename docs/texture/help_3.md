```C
#include <math.h>
#include <stdbool.h>

static t_texture	*ft_select_texture(t_cub *data, t_ray *ray)
{
	if (!data || !ray)
		return (NULL);
	if (ray->side_hit == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&data->east);
		return (&data->west);
	}
	if (ray->ray_dir_y > 0)
		return (&data->south);
	return (&data->north);
}

static int	ft_compute_tex_x(t_texture_image *timg, t_ray *ray)
{
	int		tex_x;

	if (!timg || !ray)
		return (0);
	tex_x = (int)(ray->wall_x * (double)timg->width);
	if ((ray->side_hit == 0 && ray->ray_dir_x > 0)
		|| (ray->side_hit == 1 && ray->ray_dir_y < 0))
		tex_x = timg->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= timg->width)
		tex_x = timg->width - 1;
	return (tex_x);
}

static int	ft_shade_color(int color)
{
	/* quick ambient shading for one side of walls */
	return ((color >> 1) & 0x7F7F7F);
}

static bool	ft_draw_wall_loop(t_cub *data, t_texture_image *timg,
				t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	if (!data || !timg || !ray)
		return (false);
	step = (double)timg->height / (double)ray->line_height;
	tex_pos = (ray->draw_start - (WIN_HEIGHT / 2.0)
				+ (ray->line_height / 2.0)) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= timg->height)
			tex_y = timg->height - 1;
		color = get_texture_pixel(timg, ray->tex_x, tex_y);
		if (ray->side_hit == 1)
			color = ft_shade_color(color);
		ft_draw_pixel(data->image, x, y, color);
		y++;
	}
	return (true);
}

bool	ft_draw_wall_column(t_cub *data, t_ray *ray, int x)
{
	t_texture			*tex;
	t_texture_image		*timg;

	if (!data || !ray)
		return (false);
	if (x < 0 || x >= WIN_WIDTH)
		return (false);
	tex = ft_select_texture(data, ray);
	if (!tex)
		return (false);
	timg = &tex->image;
	if (!timg || !timg->img || timg->width <= 0 || timg->height <= 0)
		return (false);
	ray->tex_x = ft_compute_tex_x(timg, ray);
	if (ray->tex_x < 0 || ray->tex_x >= timg->width)
		return (false);
	return (ft_draw_wall_loop(data, timg, ray, x));
}
```
