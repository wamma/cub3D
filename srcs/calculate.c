#include "../cub3D.h"

// void	put_e_or_w_dir_plane(t_cub *cub, int dir)
// {
// 	if (dir == 'E')
// 	{
// 		cub->dir.x = 1;
// 		cub->dir.y = 0;
// 		cub->plane.x = 0;
// 		cub->plane.y = -0.66;
// 	}
// 	else if (dir == 'W')
// 	{
// 		cub->dir.x = -1;
// 		cub->dir.y = 0;
// 		cub->plane.x = 0;
// 		cub->plane.y = 0.66;
// 	}
// }

// void	put_s_or_n_dir_plane(t_cub *cub, int dir)
// {
// 	if (dir == 'S')
// 	{
// 		cub->dir.x = 0;
// 		cub->dir.y = -1;
// 		cub->plane.x = -0.66;
// 		cub->plane.y = 0;
// 	}
// 	else if (dir == 'N')
// 	{
// 		cub->dir.x = 0;
// 		cub->dir.y = 1;
// 		cub->plane.x = 0.66;
// 		cub->plane.y = 0;
// 	}
// }
 
// void	get_starting_direction_and_plane(t_cub *cub)
// {
// 	int	starting_dir;

// 	starting_dir = cub->info_map->starting_direction;
// 	if (starting_dir == 'E' || starting_dir == 'W')
// 		put_e_or_w_dir_plane(cub, starting_dir);
// 	else if (starting_dir == 'S' || starting_dir == 'N')
// 		put_s_or_n_dir_plane(cub, starting_dir);
// }

static void	get_calc_info(t_calc *calc, t_cub *cub, int x)
{
	calc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	calc->ray_dir_x = cub->dir.x + (cub->plane.x * calc->camera_x);
	calc->ray_dir_y = cub->dir.y + (cub->plane.y * calc->camera_x);
	calc->map_x = (int)cub->pos.x;
	calc->map_y = (int)cub->pos.y;
	calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
	calc->delta_dist_y = fabs(1/ calc->ray_dir_y);
	calc->hit = 0;
}

static void	get_side_dist(t_calc *calc, t_cub *cub)
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

static void	get_side(t_calc *calc, t_cub *cub)
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

static void	determine_wall_direction(t_calc *calc, t_cub *cub)
{
	if (calc->side == 0)
	{
		if (cub->dir.x > 0)
			calc->wall_direction = EAST; // texture[0] -> east
		else
			calc->wall_direction = WEST; // texture[0] -> west
	}
	else if (calc->side == 1)
	{
		if (cub->dir.y < 0)
			calc->wall_direction = SOUTH; // texture[0] -> south
		else
			calc->wall_direction = NORTH; // texture[0] -> north
	}
}

static void	get_perp_wall_dist(t_calc *calc, t_cub *cub)
{
	if (calc->side == 0)
		calc->perp_wall_dist = (calc->map_x - cub->pos.x + (1 - calc->step_x) / 2) / calc->ray_dir_x;
	else
		calc->perp_wall_dist = (calc->map_y - cub->pos.y + (1 - calc->step_y) / 2) / calc->ray_dir_y;
}

static void	get_draw_start_and_end(t_calc *calc)
{
	calc->line_length = (int)(WIN_HEIGHT / (calc->perp_wall_dist));
	calc->draw_start = -(calc->line_length) / 2 + WIN_HEIGHT / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = calc->line_length / 2 + WIN_HEIGHT / 2;
	if (calc->draw_end >= WIN_HEIGHT)
		calc->draw_end = WIN_HEIGHT - 1;

}

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

void	render_color(t_calc *calc, t_cub *cub)
{
	if (cub->info_map->map[calc->map_y][calc->map_x] == '1')
		calc->color = 0xFF0000;
	else
		calc->color = 0xFFFF00; // yellow
	if (calc->side == 1)
		calc->color = calc->color / 2; // green
}

void	calculate(t_cub *cub)
{
	int		x;
	
	t_calc	*calc;

	calc = init_s_calc(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		// printf("%d\n", calc->draw_start);
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		get_side(calc, cub);
		// determine_wall_direction(calc, cub);
		get_perp_wall_dist(calc, cub);
		get_draw_start_and_end(calc);
		render_color(calc, cub);
		ver_line(cub, x, calc->draw_start, calc->draw_end, calc->color);
		x++;
	}
}
