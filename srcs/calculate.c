#include "../cub3D.h"

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

static void	get_wall_tex_num(t_calc *calc, t_cub *cub)
{
	if (calc->side == 0)
	{
		if (cub->dir.x > 0)
			calc->tex_num = EAST;
		else
			calc->tex_num = WEST;
	}
	else if (calc->side == 1)
	{
		if (cub->dir.y > 0)
			calc->tex_num = NORTH;
		else
			calc->tex_num = SOUTH;
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

static void	get_wall_x_tex_x(t_calc *calc, t_cub *cub)
{
	int	tex_width;

	tex_width = cub->img_texture[calc->tex_num].width;
	if (calc->side == 0)
		calc->wall_x = cub->pos.y + calc->perp_wall_dist * calc->ray_dir_y;
	else
		calc->wall_x = cub->pos.x + calc->perp_wall_dist * calc->ray_dir_x;
	calc->wall_x -= floor((calc->wall_x));

	
	//calc->tex_x = (int)(calc->wall_x * (double)tex_width);
	calc->tex_x = (int)(calc->wall_x * (double)tex_width);
	if (calc->side == 0 && calc->ray_dir_x > 0)
		calc->tex_x = tex_width - calc->tex_x - 1;
	if (calc->side == 1 && calc->ray_dir_y < 0)
		calc->tex_x = tex_width - calc->tex_x - 1;
}

static void	get_step_and_tex_pos(t_calc *calc, t_cub *cub)
{
	int	tex_height;

	tex_height = cub->img_texture[calc->tex_num].height;
	calc->step = 1.0 * tex_height / calc->line_length;
	calc->tex_pos = (calc->draw_start - WIN_HEIGHT / 2 + calc->line_length / 2) * calc->step;
}


static void	draw_wall(t_calc *calc, t_cub *cub, int x)
{
	t_image	*img;
	int	tex_height;
	int	tex_width;
	int	y;

	tex_height = cub->img_texture[calc->tex_num].height;
	tex_width = cub->img_texture[calc->tex_num].width;
	img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	y = calc->draw_start;
	while (y < calc->draw_end)
	{
		calc->tex_y = (int)calc->tex_pos & (tex_height - 1);
		calc->tex_pos += calc->step;
		img->data_ptr[tex_width * calc->tex_y + calc->tex_x] = cub->img_texture[calc->tex_num].data_ptr[tex_width * calc->tex_y + calc->tex_x];
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, img->img_ptr, 0, 0);
	//while(y < calc->draw_end)
	//{
	//	calc->tex_y = (int)calc->tex_pos & (tex_height - 1);
	//	calc->tex_pos += calc->step;
	//	cub->img_texture[calc->tex_num].texture[y] = cub->img_texture[calc->tex_num].data_ptr[tex_width * calc->tex_y + calc->tex_x];
	//	y++;
	//}
}
/*
//origin
static void	draw_wall(t_calc *calc, t_cub *cub, int x)
{
	int	tex_height;
	int	tex_width;
	int	y;

	tex_height = cub->img_texture[calc->tex_num].height;
	tex_width = cub->img_texture[calc->tex_num].width;
	y = calc->draw_start;
	while (y < calc->draw_end)
	{
		calc->tex_y = (int)calc->tex_pos & (tex_height - 1);
		calc->tex_pos += calc->step;
		cub->buf[y] = cub->img_texture[calc->tex_num].data_ptr[tex_width * calc->tex_y + calc->tex_x];
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, (void *)cub->buf, 0, 0);
	//while(y < calc->draw_end)
	//{
	//	calc->tex_y = (int)calc->tex_pos & (tex_height - 1);
	//	calc->tex_pos += calc->step;
	//	cub->img_texture[calc->tex_num].texture[y] = cub->img_texture[calc->tex_num].data_ptr[tex_width * calc->tex_y + calc->tex_x];
	//	y++;
	//}

}
*/

 void	render_color(t_calc *calc, t_cub *cub)
 {
 	mlx_put_image_to_window(cub->mlx, cub->win, (void *)cub->img_texture[calc->tex_num].img_ptr, 0, 0);
 }


t_calc *calculate(t_cub *cub)
{
	int		x;
	
	t_calc	*calc;

	calc = init_s_calc();
	x = 0;
	//cub->buf = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		get_side(calc, cub);
		get_perp_wall_dist(calc, cub);
		get_draw_start_and_end(calc);
		get_wall_tex_num(calc, cub);
		get_wall_x_tex_x(calc, cub);
		get_step_and_tex_pos(calc, cub);
		draw_wall(calc, cub, x);
		x++;
	}
	//render_color(calc, cub);
	return (calc);
}
