#include "../cub3D.h"

void	init_camera_dir_S_n_N(t_camera *camera, char c)
{
	if (c == 'S')
	{
		camera->dir.x = 0;
		camera->dir.y = -1;
		camera->plane.x = camera->pos.x - 0.66;
		camera->plane.y = camera->pos.y;
	}
	else if (c == 'N')
	{
		camera->dir.x = 0;
		camera->dir.y = 1;
		camera->plane.x = camera->pos.x + 0.66;
		camera->plane.y = camera->pos.y;
	}
}

void	init_camera_dir(t_camera *camera, char c)
{
	if (c == 'E')
	{
		camera->dir.x = 1;
		camera->dir.y = 0;
		camera->plane.x = camera->pos.x;
		camera->plane.y = camera->pos.y - 0.66;
	}
	else if (c == 'W')
	{
		camera->dir.x = -1;
		camera->dir.y = 0;
		camera->plane.x = camera->pos.x;
		camera->plane.y = camera->pos.y + 0.66;
	}
	else
		init_camera_dir_S_n_N(camera, c);
}

void	init_s_camera(t_camera *camera, t_map *info_map)
{
	camera->pos.x = info_map->starting_x;
	camera->pos.y = info_map->starting_y;
	init_camera_dir(camera, info_map->starting_direction);
}
