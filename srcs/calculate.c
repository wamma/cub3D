#include "../cub3D.h"

void	put_e_or_w_dir_plane(t_cub *cub, int dir)
{
	if (dir == 'E')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = -0.66;
	}
	else if (dir == 'W')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = 0.66;
	}
}

void	put_s_or_n_dir_plane(t_cub *cub, int dir)
{
	if (dir == 'S')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
		cub->plane.x = -0.66;
		cub->plane.y = 0;
	}
	else if (dir == 'N')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
		cub->plane.x = 0.66;
		cub->plane.y = 0;
	}
}
 
void	get_starting_dir_and_plane(t_cub *cub)
{
	int	starting_dir;

	starting_dir = cub->info_map->starting_direction;
	if (starting_dir == 'E' || starting_dir == 'W')
		put_e_or_w_dir_plane(cub, starting_dir);
	else if (starting_dir == 'S' || starting_dir == 'N')
		put_s_or_n_dir_plane(cub, starting_dir);
}

void	get_calc_info(t_calc *calc, t_cub *cub, int x)
{
	calc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	calc->ray_dir_x = cub->dir.x + (cub->plane.x * calc->camera_x);
	calc->ray_dir_y = cub->dir.y + (cub->plane.y * calc->camera_x);
	calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
	calc->delta_dist_y = fabs(1/ calc->ray_dir_y);
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
		calc->side_dist_x = (calc->map_x + 1.0 - cub->pos.x) * calc->delta_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (cub->pos.y - calc->map_y) * calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = (calc->map_y + 1.0 - cub->pos.y) * calc->delta_dist_y;
	}
}

void	calculate(t_cub *cub)
{
	int		x;
	
	t_calc	*calc;

	calc = init_s_calc(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		x++;
	}
}
