#include "../cub3D.h"

void	load_texture(t_cub *cub, char *path, int i)
{
	int		x;
	int		y;
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image) * 1);
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	cub->img_texture[i].width = img->width;
	cub->img_texture[i].height = img->height;
	cub->img_texture[i].texture = (int *)malloc(sizeof(int) * (img->width * img->height));
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cub->img_texture[i].texture[img->width * y + x] = img->data_ptr[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
}

void	load_image(t_cub *cub)
{
	load_texture(cub, cub->info_map->ea_path, 0);
	load_texture(cub, cub->info_map->we_path, 1);
	load_texture(cub, cub->info_map->so_path, 2);
	load_texture(cub, cub->info_map->no_path, 3);
	printf("texture[0].width: %d height: %d\n", cub->img_texture[0].width, cub->img_texture[0].height);
	printf("texture[1].width: %d height: %d\n", cub->img_texture[1].width, cub->img_texture[1].height);
	printf("texture[2].width: %d height: %d\n", cub->img_texture[2].width, cub->img_texture[2].height);
	printf("texture[3].width: %d height: %d\n", cub->img_texture[3].width, cub->img_texture[3].height);
}
