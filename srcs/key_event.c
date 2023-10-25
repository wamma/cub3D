/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:18 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 14:27:19 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	key_code_W_S(t_cub *cub, int key_code)
{
	if (key_code == KEY_W)
	{
		if (cub->info_map->map[(int)(cub->pos.y + cub->dir.y * cub->move_speed)][(int)(cub->pos.x)] != WALL)
			cub->pos.y += cub->dir.y * cub->move_speed;
		if (cub->info_map->map[(int)(cub->pos.y)][(int)(cub->pos.x + cub->dir.x * cub->move_speed)] != WALL)
			cub->pos.x += cub->dir.x * cub->move_speed;
	}
	if (key_code == KEY_S)
	{
		if (cub->info_map->map[(int)(cub->pos.y - cub->dir.y * cub->move_speed)][(int)cub->pos.x] != WALL)
			cub->pos.y -= cub->dir.y * cub->move_speed;
		if (cub->info_map->map[(int)cub->pos.y][(int)(cub->pos.x - cub->dir.x * cub->move_speed)] != WALL)
			cub->pos.x -= cub->dir.x * cub->move_speed;
	}
}

void	key_code_A_D(t_cub *cub, int key_code)
{
	if (key_code == KEY_A)
	{
		if (cub->info_map->map[(int)(cub->pos.y - cub->plane.y * cub->move_speed)][(int)(cub->pos.x)] != WALL)
			cub->pos.y -= cub->plane.y * cub->move_speed;
		if (cub->info_map->map[(int)(cub->pos.y)][(int)(cub->pos.x - cub->plane.x * cub->move_speed)] != WALL)
			cub->pos.x -= cub->plane.x * cub->move_speed;
	}
	if (key_code == KEY_D)
	{
		if (cub->info_map->map[(int)(cub->pos.y + cub->plane.y * cub->move_speed)][(int)(cub->pos.x)] != WALL)
			cub->pos.y += cub->plane.y * cub->move_speed;
		if (cub->info_map->map[(int)(cub->pos.y)][(int)(cub->pos.x + cub->plane.x * cub->move_speed)] != WALL)
			cub->pos.x += cub->plane.x * cub->move_speed;
	}
}

void	key_code_arrow(t_cub *cub, int key_code)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key_code == KEY_LEFT)
	{
		old_dir_x = cub->dir.x;
		cub->dir.x = cub->dir.x * cos(cub->rot_speed) - cub->dir.y * sin(cub->rot_speed);
		cub->dir.y = old_dir_x * sin(cub->rot_speed) + cub->dir.y * cos(cub->rot_speed);
		old_plane_x = cub->plane.x;
		cub->plane.x = cub->plane.x * cos(cub->rot_speed) - cub->plane.y * sin(cub->rot_speed);
		cub->plane.y = old_plane_x * sin(cub->rot_speed) + cub->plane.y * cos(cub->rot_speed);
	}
	if (key_code == KEY_RIGHT)
	{
		old_dir_x = cub->dir.x;
		cub->dir.x = cub->dir.x * cos(-cub->rot_speed) - cub->dir.y * sin(-cub->rot_speed);
		cub->dir.y = old_dir_x * sin(-cub->rot_speed) + cub->dir.y * cos(-cub->rot_speed);
		old_plane_x = cub->plane.x;
		cub->plane.x = cub->plane.x * cos(-cub->rot_speed) - cub->plane.y * sin(-cub->rot_speed);
		cub->plane.y = old_plane_x * sin(-cub->rot_speed) + cub->plane.y * cos(-cub->rot_speed);
	}
}

int	key_press(int key_code, t_cub *cub)
{
	if (key_code == KEY_ESC)
		exit(0);
	key_code_W_S(cub, key_code);
	key_code_A_D(cub, key_code);
	key_code_arrow(cub, key_code);
	mlx_clear_window(cub->mlx, cub->win);
	main_loop(cub);
	return (0);
}