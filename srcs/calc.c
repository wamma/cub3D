#include "../cub3D.h"

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
		if (cub->info_map->map[calc->map_x][calc->map_y]  == '1')
			calc->hit = 1;
	}
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


//int	determine_wall_direction(t_calc *calc)
//{
//	if (calc->side == 0)
//	{
//		if (calc->ray_dir_x > 0)

//		else
//	}// east, west
//	else if (calc->side == 1)
//	{
//		if (calc->ray_dir_y )
//	}// south, north
//}

void	get_tex_num_wall_x_tex_x(t_calc *calc, t_cub *cub)
{

	//calc->tex_num = cub->info_map->map[calc->map_x][calc->map_y] - 1;//어떤 텍스쳐를 입힐지
	

	//어떤 텍스쳐를 입힐지
	if (calc->side == 0)
		calc->wall_x = cub->pos.y + calc->perp_wall_dist * calc->ray_dir_y;
	else
		calc->wall_x = cub->pos.x + calc->perp_wall_dist * calc->ray_dir_x;
	calc->wall_x -= floor(calc->wall_x);
	calc->tex_x = (int)(calc->wall_x * (double)TEX_WIDTH);
	if (calc->side == 0 && calc->ray_dir_x > 0)
		calc->tex_x = TEX_WIDTH - calc->tex_x - 1;
	if (calc->side == 1 && calc->ray_dir_y < 0)
		calc->tex_x = TEX_WIDTH - calc->tex_x - 1;
}

void	get_textured_color(t_calc *calc, t_cub *cub, int x)
{
	int y;

	y = calc->draw_start;
	calc->step = 1.0 * TEX_HEIGHT / calc->line_length;
	calc->tex_pos = (calc->draw_start - WIN_HEIGHT / 2 + calc->line_length / 2) * calc->step;
	while (y < calc->draw_end)
	{
		calc->tex_y = (int)calc->tex_pos & (TEX_HEIGHT - 1);
		calc->tex_pos += calc->step;
		calc->color = cub->texture[calc->tex_num][TEX_HEIGHT * calc->tex_y + calc->tex_x];
		cub->buf[x][y] = calc->color;
		cub->re_buf = 1;
		y++;
	}
}

void	calc(t_cub *cub)
{
	int		x;
	t_calc	*calc;

	calc = init_s_calc();
	x = 0;
	// if (cub->re_buf == 1)
	// 	clear_buf(cub);
	while (x < WIN_WIDTH)
	{
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		get_side(calc, cub);
		get_perp_wall_dist(calc, cub);
		get_draw_start_and_end(calc);
		get_tex_num_wall_x_tex_x(calc, cub);
		get_textured_color(calc, cub, x);
		// render_color(calc, cub);
		// ver_line(cub, x, calc->draw_start, calc->draw_end, calc->color);
		x++;
	}
}