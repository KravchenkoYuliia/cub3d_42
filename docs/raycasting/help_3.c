t_ray	init_ray_struct(t_player *player, float ray_angle)
{
	t_ray	ray;

	ray.pos_x = player->x;
	ray.pos_y = player->y;
	ray.map_x = (int)player->x;
	ray.map_y = (int)player->y;
	ray.raydirx = cos(ray_angle);
	ray.raydiry = sin(ray_angle);
	ray.deltadist_x = fabs(1.0 / ray.raydirx);
	ray.deltadist_y = fabs(1.0 / ray.raydiry);
	ray.step_x = 0;
	ray.step_y = 0;
	ray.sidedist_x = 0;
	ray.sidedist_y = 0;
	calc_ray_dir(&ray);
	return (ray);
}

float	calc_rays(t_data *data, float ray_angle)
{
	t_ray	ray;
	int		side;
	float	dist;
	float	dist_uncorrected;

	ray = init_ray_struct(&data->player, ray_angle);
	side = 0;
	calc_hit(data, &ray, data->param.map, &side);
	if (side == 0)
		dist_uncorrected = ray.sidedist_x - ray.deltadist_x;
	else
		dist_uncorrected = ray.sidedist_y - ray.deltadist_y;
	data->hit.wall_dir = find_dir(&ray, side);
	data->hit.wall_hit_x = calc_wall_hit_x(&ray, side, dist_uncorrected);
	dist = dist_uncorrected * cos(ray_angle - data->player.angle);
	return (dist);
}

void	rays_process(t_data *data, t_player *player, t_config *c)
{
	int		i;
	float	ray_angle;
	float	dist;
	float	wall_height;

	i = 0;
	while (i < c->nbr_rays)
	{
		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / c->nbr_rays);
		dist = calc_rays(data, ray_angle);
		if (dist < 0.001)
			dist = 0.001;
		wall_height = SCREENHEIGHT / dist;
		draw_wall(data, c, i, wall_height);
		i++;
	}
}

int	raycasting(t_data *data)
{
	clear_image(&data->img, SCREENWIDTH, SCREENHEIGHT);
	move_player(&data->player, &data->conf);
	cast_ceiling(&data->img, data->asset.ceiling);
	cast_floor(&data->img, data->asset.floor);
	rays_process(data, &data->player, &data->conf);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
