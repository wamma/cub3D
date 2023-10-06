#include "../cub3D.h"

typedef struct s_calc
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	int		color;
	int		line_length;
	int		draw_start;
	int		draw_end;
}	t_calc;

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

t_calc	*init_s_calc()
{
	t_calc	*calc;

	calc = (t_calc *)malloc(sizeof(t_calc));
	if (calc == NULL)
		ft_error("malloc error");
	ft_memset(calc, 0, sizeof(t_calc));
	return (calc);
}

void	get_calc_info(t_calc *calc, t_cub *cub, int x)
{
		calc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		calc->ray_dir_x = cub->dir.x + cub->plane.x * calc->camera_x;
		calc->ray_dir_y = cub->dir.y + cub->plane.y * calc->camera_x;
		calc->map_x = (int)cub->pos.x ;
		calc->map_y = (int)cub->pos.y;
		calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
		calc->delta_dist_y = fabs(1 / calc->ray_dir_y);
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
		if (cub->map[calc->map_x][calc->map_y]  == '1')
			calc->hit = 1;
	}
}

void	render_color(t_calc *calc, t_cub *cub)
{
	if (cub->map[calc->map_x][calc->map_y] == 1)
		calc->color = 0xFF0000;
	else
		calc->color = 0xFFFF00;
	if (calc->side == 1)
		calc->color = calc->color / 2;
}

void	get_perp_wall_dist(t_calc *calc, t_cub *cub)
{
	if (calc->side == 0)
		calc->perp_wall_dist = \
		(calc->map_x - cub->pos.x + (1 - calc->step_x) / 2) / calc->ray_dir_x;
	else
		calc->perp_wall_dist = \
		(calc->map_y - cub->pos.y + (1 - calc->step_y) / 2) / calc->ray_dir_y;
}

void	get_draw_start_and_end(t_calc *calc)
{
	calc->line_length = (int)(WIN_HEIGHT / (calc->perp_wall_dist * 2));
	calc->draw_start = -(calc->line_length) / 2 + WIN_HEIGHT / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = calc->line_length / 2 + WIN_HEIGHT / 2;
	if (calc->draw_end >= WIN_HEIGHT)
		calc->draw_end = WIN_HEIGHT - 1;
}

void	calc(t_cub *cub)
{
	int		x;
	t_calc	*calc;

	calc = init_s_calc();
	x = 0;
	while (x < WIN_WIDTH)
	{
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		get_side(calc, cub);
		get_perp_wall_dist(calc, cub);
		get_draw_start_and_end(calc);
		render_color(calc, cub);
		ver_line(cub, x, calc->draw_start, calc->draw_end, calc->color);
		x++;
	}
}

int	main_loop(t_cub *cub)
{
	calc(cub);
	return (0);
}
