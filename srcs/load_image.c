#include "../cub3D.h"

void	load_texture(t_cub *cub, char *path, int i)
{
	int		x;
	int		y;
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data_ptr = (int *)mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	cub->img_texture[i].width = img->width;
	cub->img_texture[i].height = img->height;
	cub->img_texture[i].bits_per_pixel = img->bits_per_pixel / 8;
	cub->img_texture[i].line_length = img->line_length;
	cub->img_texture[i].endian = img->endian;
	cub->img_texture[i].texture = (int *)malloc(sizeof(int) * TEX_HEIGHT);
	cub->img_texture[i].data_ptr = img->data_ptr;
	mlx_destroy_image(cub->mlx, img->img_ptr);
}

void	load_image(t_cub *cub)
{
	load_texture(cub, cub->info_map->ea_path, 0);
	load_texture(cub, cub->info_map->we_path, 1);
	load_texture(cub, cub->info_map->so_path, 2);
	load_texture(cub, cub->info_map->no_path, 3);
}
