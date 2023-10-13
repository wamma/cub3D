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
	if (cub->map[calc->map_x][calc->map_y] == 1)
		calc->color = 0xFF0000;
	else
		calc->color = 0xFFFF00; // yellow
	if (calc->side == 1)
		calc->color = calc->color / 2; // green
}

void	load_texture(t_cub *cub, int *texture, char *path, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	while (y < img->width)
	{
		x = 0;
		while (x < img->height)
		{
			texture[img->width * y + x] = img->data_ptr[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
}

void	load_image(t_cub *cub)
{
	load_texture(cub, cub->texture[0], cub->info_map->no_path, cub->img);
	load_texture(cub, cub->texture[1], cub->info_map->so_path, cub->img);
	load_texture(cub, cub->texture[2], cub->info_map->we_path, cub->img);
	load_texture(cub, cub->texture[3], cub->info_map->ea_path, cub->img);
}

int	main_loop(t_cub *cub)
{
	load_image(cub);
	calc(cub);
	draw(cub);
	return (0);
}
