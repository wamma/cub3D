#include "../cub3D.h"

void	draw(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_HEIGHT)
	{
		y = 0;
		while (y < WIN_WIDTH)
		{
			cub->img->data_ptr[y * WIN_HEIGHT + x] = cub->buf[x][y];
			y++;
		}
		x++;
	}
}

// void	ver_line(t_cub *cub, int x, int draw_start, int draw_end, int color)
// {
// 	int y;

// 	y = draw_start;
// 	while (y <= draw_end)
// 	{
// 		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
// 		y++;
// 	}
// }

// void	render_color(t_calc *calc, t_cub *cub)
// {
// 	if (cub->map[calc->map_x][calc->map_y] == 1)
// 		calc->color = 0xFF0000;
// 	else
// 		calc->color = 0xFFFF00; // yellow
// 	if (calc->side == 1)
// 		calc->color = calc->color / 2; // green
// }

void	load_texture(t_cub *cub, int i, char *path)
{
	int	x;
	int	y;
	t_image *img;

	img = malloc(sizeof(t_image));
	if (!img)
		ft_error("Failed malloc\n");
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	cub->texture[i] = (int *)malloc(sizeof(int) * (img->width * img->height));
	x = 0;
	while (x < img->height)
	{
		y = 0;
		while (y < img->height)
		{
			cub->texture[i][img->width * y + x] = img->data_ptr[img->width * y + x];
			y++;
		}
		x++;
	}
	if (i == 3)
	{
		for (int k = 0; k < img->height * img->width; k++)
		{
			printf("%d, ", cub->texture[i][k]);
		}
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
	free(img); // leak 체크 해야됨(img_ptr, data_ptr 해제를 해야하는가)
}

void	load_image(t_cub *cub)
{
	load_texture(cub, 0, cub->info_map->ea_path);
	load_texture(cub, 1, cub->info_map->we_path);
	load_texture(cub, 2, cub->info_map->so_path);
	load_texture(cub, 3, cub->info_map->no_path);
}

int	main_loop(t_cub *cub)
{
	calc(cub);
	draw(cub);
	return (0);
}
