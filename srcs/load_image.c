#include "../cub3D.h"

int	*load_texture(t_cub *cub, char *path, t_image *img, int i)
{
	int	x;
	int	y;
	int	*result;

	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	cub->texture[i].width = img->width;
	cub->texture[i].height = img->height;
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	result = (int *)malloc(sizeof(int) * (img->width * img->height));
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			result[img->width * y + x] = img->data_ptr[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
	return (result);
}

void	load_image(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUMBER)
	{
		if (i == 0)
			cub->texture[i].texture = load_texture(cub, cub->info_map->ea_path, cub->img, i);
		else if (i == 1)
			cub->texture[i].texture = load_texture(cub, cub->info_map->we_path, cub->img, i);
		else if (i == 2)
			cub->texture[i].texture = load_texture(cub, cub->info_map->so_path, cub->img, i);
		else
			cub->texture[i].texture = load_texture(cub, cub->info_map->no_path, cub->img, i);
		i++;
	}
	printf("texture[0].width: %d height: %d\n", cub->texture[0].width, cub->texture[0].height);
	printf("texture[1].width: %d height: %d\n", cub->texture[1].width, cub->texture[1].height);
	printf("texture[2].width: %d height: %d\n", cub->texture[2].width, cub->texture[2].height);
	printf("texture[3].width: %d height: %d\n", cub->texture[3].width, cub->texture[3].height);
}
