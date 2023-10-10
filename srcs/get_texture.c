#include "../cub3D.h"

int		*get_texture_image(t_cub *cub, char *path, int i)
{
	t_image	*img;
	char	*result;
	int		row;
	int		col;

	img->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	cub->texture[i].width = img->width;
	cub->texture[i].height = img->height;
	img->data_ptr = mlx_get_data_addr(img->img_ptr, \
		img->bits_per_pixel, img->line_length, img->endian);
	result = (int *)malloc(sizeof(int) * (img->width * img->height));
	row = 0;
	while (row < img->height)
	{
		col = 0;
		while (col < img->width)
		{
			result[img->width * row + col] = img->data_ptr[img->width * row + col];
			col++;
		}
		row++;
	}
	mlx_destroy_image(cub->mlx, img->img_ptr);
	return (result);
}

void	get_s_texture_info(t_cub *cub, t_map *info_map)
{
	int	i;
	i = 0;
	cub->texture[0].texture_path = info_map->ea_path;
	cub->texture[1].texture_path = info_map->we_path;
	cub->texture[2].texture_path = info_map->so_path;
	cub->texture[3].texture_path = info_map->no_path;
	while (i < TEXTURE_NUMBER)
	{
		cub->texture[i].texture = get_texture_image(cub, cub->texture[i].texture_path, i);
		i++;
	}
}