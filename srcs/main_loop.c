/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 17:50:11 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put(t_image *win_img, int x, int y, int color)
{
	char	*dest;

	dest = (char *)(win_img->data_ptr);
	dest += (y * win_img->line_length + x * (win_img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

t_calc	*calculate(t_cub *cub)
{
	int		x;
	t_calc	*calc;
	t_image	win_img;

	calc = init_s_calc();
	x = 0;
	win_img.img_ptr = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	win_img.data_ptr = (int *)mlx_get_data_addr(win_img.img_ptr, \
	&win_img.bits_per_pixel, &win_img.line_length, &win_img.endian);
	while (x < WIN_WIDTH)
	{
		get_calc_info(calc, cub, x);
		get_side_dist(calc, cub);
		get_side(calc, cub);
		get_perp_wall_dist(calc, cub);
		get_draw_start_and_end(calc);
		get_wall_tex_num(calc);
		get_wall_x_tex_x(calc, cub);
		get_step_and_tex_pos(calc, cub);
		draw_floor_ceiling(calc, cub, &win_img, x);
		draw_wall(calc, cub, x, &win_img);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, win_img.img_ptr, 0, 0);
	mlx_destroy_image(cub->mlx, win_img.img_ptr);
	return (calc);
}

int	main_loop(t_cub *cub)
{
	t_calc	*calc;

	calc = calculate(cub);
	free(calc);
	return (0);
}
