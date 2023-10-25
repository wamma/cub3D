/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:43:07 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_calc_info(t_calc *calc, t_cub *cub, int x)
{
	calc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	calc->ray_dir_x = cub->dir.x + (cub->plane.x * calc->camera_x);
	calc->ray_dir_y = cub->dir.y + (cub->plane.y * calc->camera_x);
	calc->map_x = (int)cub->pos.x;
	calc->map_y = (int)cub->pos.y;
	calc->delta_dist_x = sqrt(1 + (calc->ray_dir_y * calc->ray_dir_y) / \
	(calc->ray_dir_x * calc->ray_dir_x));
	calc->delta_dist_y = sqrt(1 + (calc->ray_dir_x * calc->ray_dir_x) / \
	(calc->ray_dir_y * calc->ray_dir_y));
	calc->hit = 0;
}

void	get_side_dist(t_calc *calc, t_cub *cub)
{
	if (calc->ray_dir_x < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (cub->pos.x - calc->map_x) * calc->delta_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = (calc->map_x + 1.0 - cub->pos.x) * \
		calc->delta_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (cub->pos.y - calc->map_y) * calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = (calc->map_y + 1.0 - cub->pos.y) * \
		calc->delta_dist_y;
	}
}

void	get_side(t_calc *calc, t_cub *cub)
{
	while (calc->hit == 0)
	{
		if (calc->side_dist_x < calc->side_dist_y)
		{
			calc->side_dist_x += calc->delta_dist_x;
			calc->map_x += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->side_dist_y += calc->delta_dist_y;
			calc->map_y += calc->step_y;
			calc->side = 1;
		}
		if (cub->info_map->map[calc->map_y][calc->map_x] == '1')
			calc->hit = 1;
	}
}

void	get_wall_tex_num(t_calc *calc)
{
	if (calc->side == 0)
	{
		if (calc->ray_dir_x > 0)
			calc->tex_num = EAST;
		else
			calc->tex_num = WEST;
	}
	else
	{
		if (calc->ray_dir_y > 0)
			calc->tex_num = NORTH;
		else
			calc->tex_num = SOUTH;
	}
}

void	get_perp_wall_dist(t_calc *calc, t_cub *cub)
{
	if (calc->side == 0)
		calc->perp_wall_dist = (calc->map_x - cub->pos.x + \
		(1 - calc->step_x) / 2) / calc->ray_dir_x;
	else
		calc->perp_wall_dist = (calc->map_y - cub->pos.y + \
		(1 - calc->step_y) / 2) / calc->ray_dir_y;
}
