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

void	init_s_cub(t_cub *cub, t_map *info_map)
{
	cub->img_texture = (t_image *)malloc(sizeof(t_image) * TEXTURE_NUMBER);
	cub->pos.x = info_map->starting_x + 0.5;
	cub->pos.y = info_map->starting_y + 0.5;
	init_camera_dir(cub, info_map->starting_direction);
	cub->move_speed = 0.05;
	cub->rot_speed = 0.05;
	init_buf(cub);
	cub->re_buf = 0;
	cub->info_map = info_map;
}

t_calc	*init_s_calc(void)
{
	t_calc	*calc;

	calc = (t_calc *)malloc(sizeof(t_calc));
	if (calc == NULL)
		ft_error("malloc error");
	ft_memset(calc, 0, sizeof(t_calc));
	return (calc);
}
