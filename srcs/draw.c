#include "../cub3D.h"

void	ver_line(t_cub *cub, int x, int draw_start, int draw_end, int color)
{
	int y;

	y = draw_start;
	while (y <= draw_end)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}

// void	calc_side_step(t_cub *cub, double ray_dir_x, double ray_dir_y, int map_x, int map_y, double delta_dist_x, double delta_dist_y, int *step_x, int *step_y)
// {
// 	if (ray_dir_x < 0)
// 	{
// 		(*step_x) = -1;
// 		side_dist_x = (cub->pos.x - map_x) * delta_dist_x;
// 	}
// 	else
// 	{
// 		(*step_x) = 1;
// 		side_dist_x = (map_x + 1.0 - cub->pos.x) * delta_dist_x;
// 	}
// 	if (ray_dir_y < 0)
// 	{
// 		(*step_y) = -1;
// 		side_dist_y = (cub->pos.y - map_y) * delta_dist_y;
// 	}
// 	else
// 	{
// 		(*step_y) = 1;
// 		side_dist_y = (map_y + 1.0 - cub->pos.y) * delta_dist_y;
// 	}
// }

// void	calc_delta_distance(double ray_dir_x, double ray_dir_y, double *delta_dist_x, double *delta_dist_y)
// {
// 	(*delta_dist_x) = fabs(1 / ray_dir_x);
// 	(*delta_dist_y) = fabs(1 / ray_dir_y);
// }

// void	hit_check_and_coloring(t_cub *cub, t_map *info_map, double ray_dir_x, double ray_dir_y, int map_x , int map_y)
// {
// 	double	delta_dist_x;
// 	double	delta_dist_y;
// 	int		step_x;
// 	int		step_y;
// 	int		side_dist_x;
// 	int		side_dist_y;

// 	calc_delta_distance(ray_dir_x, ray_dir_y, &delta_dist_x, &delta_dist_y);
// 	calc_side_step(cub, ray_dir_x, ray_dir_y, map_x, map_y, delta_dist_x, delta_dist_y, &step_x, &step_y);
// 	check_hit(info_map, map_x, map_y);
// 	draw_wall_distance(cub->pos.x, cub->pos.y,(1 - step_x)/2, (1 - step.y)/2);
// 	coloring(info_map, map_x, map_y);
// }

// void	map_position(t_cub *cub, int *map_x, int *map_y)
// {
// 	(*map_x) = (int)cub->pos.x;
// 	(*map_y) = (int)cub->pos.y;
// }

// void	calc_ray_direction(t_cub *cub, double camera_x, double *ray_dir_x, double *ray_dir_y)
// {
// 	(*ray_dir_x) = cub->dir.x + cub->plane.x * camera_x;
// 	(*ray_dir_y) = cub->dir.y + cub->plane.y * camera_x;
// }

// void	calc_ray(t_cub *cub, t_map *info_map, double camera_x)
// {
// 	double	ray_dir_x;
// 	double	ray_dir_y;
// 	int		map_x;
// 	int		map_y;

// 	calc_ray_direction(cub, camera_x, &ray_dir_x, &ray_dir_y);
// 	map_position(cub, &map_x, &map_y);
// 	hit_check_and_coloring(cub, info_map, ray_dir_x, ray_dir_y);
// }

void	calc(t_cub *cub)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_length;
	int		draw_start;
	int		draw_end;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = cub->dir.x + cub->plane.x * camera_x;
		ray_dir_y = cub->dir.y + cub->plane.y * camera_x;

		map_x = (int)cub->pos.x;
		map_y = (int)cub->pos.y;

		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);

		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (cub->pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - cub->pos.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (cub->pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - cub->pos.y) * delta_dist_y;
		}

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (cub->map[map_x][map_y]  == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - cub->pos.x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - cub->pos.y + (1 - step_y) / 2) / ray_dir_y;
		
		line_length = (int)(WIN_HEIGHT / perp_wall_dist);

		draw_start = -line_length / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_length / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		
		if (cub->map[map_x][map_y] == 1)
			color = 0xFF0000;
		else
			color = 0xFFFF00;
		if (side == 1)
			color = color / 2;
		ver_line(cub, x, draw_start, draw_end, color);
		x++;
	}
}

int	main_loop(t_cub *cub)
{
	calc(cub);
	return (0);
}
