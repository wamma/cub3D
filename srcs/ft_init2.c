#include "../cub3D.h"

void	init_camera_dir_S_n_N(t_cub *cub, char c)
{
	if (c == 'S')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
		cub->plane.x = -0.66;
		cub->plane.y = 0;
	}
	else if (c == 'N')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
		cub->plane.x = 0.66;
		cub->plane.y = 0;
	}
}

void	init_camera_dir(t_cub *cub, char c)
{
	if (c == 'E')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = -0.66;
	}
	else if (c == 'W')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = 0.66;
	}
	else
		init_camera_dir_S_n_N(cub, c);
}

void	init_s_camera(t_cub *cub, t_map *info_map)
{
	cub->pos.x = info_map->starting_x + 0.5;
	cub->pos.y = info_map->starting_y + 0.5;
	init_camera_dir(cub, info_map->starting_direction);
	cub->move_speed = 0.05;
	cub->rot_speed = 0.05;
	cub->map = copy_char_map(info_map);
}
