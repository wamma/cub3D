/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:42:25 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:43:04 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_wall_x_tex_x(t_calc *calc, t_cub *cub)
{
	int	tex_width;

	tex_width = cub->img_texture[calc->tex_num].width;
	if (calc->side == 0)
		calc->wall_x = cub->pos.y + calc->perp_wall_dist * calc->ray_dir_y;
	else
		calc->wall_x = cub->pos.x + calc->perp_wall_dist * calc->ray_dir_x;
	calc->wall_x -= floor((calc->wall_x));
	calc->tex_x = (int)(calc->wall_x * (double)tex_width);
	if (calc->side == 0 && calc->ray_dir_x > 0)
		calc->tex_x = tex_width - calc->tex_x - 1;
	if (calc->side == 1 && calc->ray_dir_y < 0)
		calc->tex_x = tex_width - calc->tex_x - 1;
}

void	get_step_and_tex_pos(t_calc *calc, t_cub *cub)
{
	int	tex_height;

	tex_height = cub->img_texture[calc->tex_num].height;
	calc->step = 1.0 * tex_height / calc->line_height;
	calc->tex_pos = (calc->draw_start - WIN_HEIGHT / 2 \
	+ calc->line_height / 2) * calc->step;
}

void	draw_wall(t_calc *calc, t_cub *cub, int x, t_image *win_img)
{
	int	tex_height;
	int	y;

	tex_height = cub->img_texture[calc->tex_num].height;
	y = calc->draw_start;
	while (y <= calc->draw_end)
	{
		calc->tex_y = (int)calc->tex_pos & (tex_height - 1);
		calc->tex_pos += calc->step;
		calc->color = cub->img_texture[calc->tex_num].data_ptr \
		[cub->img_texture[calc->tex_num].width * calc->tex_y + calc->tex_x];
		my_mlx_pixel_put(win_img, x, y, calc->color);
		y++;
	}
}

void	draw_floor_ceiling(t_calc *calc, t_cub *cub, t_image *win_img, int x)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	y;

	y = -1;
	while (++y < calc->draw_start)
	{
		r = cub->info_map->ceiling->r;
		g = cub->info_map->ceiling->g;
		b = cub->info_map->ceiling->b;
		color = (r << 16) + (g << 8) + b;
		my_mlx_pixel_put(win_img, x, y, color);
	}
	y = calc->draw_end;
	while (y < WIN_HEIGHT)
	{
		r = cub->info_map->floor->r;
		g = cub->info_map->floor->g;
		b = cub->info_map->floor->b;
		color = (r << 16) + (g << 8) + b;
		my_mlx_pixel_put(win_img, x, y, color);
		y++;
	}
}

void	get_draw_start_and_end(t_calc *calc)
{
	if (calc->perp_wall_dist == 0)
		calc->perp_wall_dist = 1;
	calc->line_height = (int)(WIN_HEIGHT / calc->perp_wall_dist);
	calc->draw_start = -(calc->line_height) / 2 + WIN_HEIGHT / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = calc->line_height / 2 + WIN_HEIGHT / 2;
	if (calc->draw_end >= WIN_HEIGHT)
		calc->draw_end = WIN_HEIGHT - 1;
}
