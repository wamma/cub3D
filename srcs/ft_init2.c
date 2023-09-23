#include "../cub3D.h"

void	init_s_camera(t_camera *camera, t_map *info_map)
{
	camera->pos.x = info_map->starting_x;
	camera->pos.y = info_map->starting_y;
	if (info_map->starting_direction == 'E')
	{
		camera->dir.x = 1;
		camera->dir.y = 0;
		camera->plane.x = camera->pos.x;
		camera->plane.y = camera->pos.y - 0.66;
	}
	else if (info_map->starting_direction == 'W')
	{
		camera->dir.x = -1;
		camera->dir.y = 0;
		camera->plane.x = camera->pos.x;
		camera->plane.y = camera->pos.y + 0.66;
	}
	else if (info_map->starting_direction == 'S')
	{
		camera->dir.x = 0;
		camera->dir.y = -1;
		camera->plane.x = camera->pos.x - 0.66;
		camera->plane.y = camera->pos.y;
	}
	else if (info_map->starting_direction == 'N')
	{
		camera->dir.x = 0;
		camera->dir.y = 1;
		camera->plane.x = camera->pos.x + 0.66;
		camera->plane.y = camera->pos.y;
	}
}
