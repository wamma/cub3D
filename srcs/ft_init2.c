#include "../cub3D.h"

void	init_camera_dir_S_n_N(t_cub *cub, char c)
{
	if (c == 'S')
	{
		cub->dir.y = 0;
		cub->dir.x = 1;
		cub->plane.y = -0.66;
		cub->plane.x = 0;
	}
	else if (c == 'N')
	{
		cub->dir.y = 0;
		cub->dir.x = -1;
		cub->plane.y = 0.66;
		cub->plane.x = 0;
	}
}

void	init_camera_dir(t_cub *cub, char c)
{
	if (c == 'E')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
		cub->plane.x = 0.66;
		cub->plane.y = 0;
	}
	else if (c == 'W')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
		cub->plane.x = -0.66;
		cub->plane.y = 0;
	}
	else
		init_camera_dir_S_n_N(cub, c);
}

void	init_s_cub(t_cub *cub, t_map *info_map)
{
	cub->pos.x = info_map->starting_x + 0.5;
	cub->pos.y = info_map->starting_y + 0.5;
	init_camera_dir(cub, info_map->starting_direction);
	cub->move_speed = 0.05;
	cub->rot_speed = 0.05;
	cub->map = copy_char_map(info_map);
	init_buf(cub);
	cub->re_buf = 0;
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

t_texture	*init_s_texture(void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		ft_error("malloc error");
	ft_memset(texture, 0, sizeof(t_texture));
	return (texture);
}