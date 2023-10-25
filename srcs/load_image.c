/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 14:31:03 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	load_texture(t_cub *cub, char *path, int i)
{
	int		x;
	int		y;
	t_image	img;

	img.img_ptr = mlx_xpm_file_to_image(cub->mlx, path, \
					&img.width, &img.height);
	img.data_ptr = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, \
					&img.line_length, &img.endian);
	cub->img_texture[i].width = img.width;
	cub->img_texture[i].height = img.height;
	cub->img_texture[i].data_ptr = (int *)malloc(sizeof(int) * \
								(img.width * img.height));
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			cub->img_texture[i].data_ptr[img.width * y + x] = \
								img.data_ptr[img.width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img.img_ptr);
}

void	load_image(t_cub *cub)
{
	load_texture(cub, cub->info_map->ea_path, EAST);
	load_texture(cub, cub->info_map->we_path, WEST);
	load_texture(cub, cub->info_map->so_path, SOUTH);
	load_texture(cub, cub->info_map->no_path, NORTH);
}
