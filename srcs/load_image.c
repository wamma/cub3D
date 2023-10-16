#include "../cub3D.h"

void	load_texture(t_cub *cub, int index, char *path)
{
	int		x;
	int		y;
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		ft_error("Error: malloc\n");
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	cub->texture[index] = (int *)malloc(sizeof(int) * (img->width * img->height));
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cub->texture[index][img->width * y + x] = img->data_ptr[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
	free(img);
}

void	load_image(t_cub *cub)
{
	load_texture(cub, 0, cub->info_map->ea_path);
	load_texture(cub, 1, cub->info_map->we_path);
	load_texture(cub, 2, cub->info_map->so_path);
	load_texture(cub, 3, cub->info_map->no_path);
}
