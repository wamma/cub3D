#include "../cub3D.h"

void	coloring_pixel(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < )
}

void	draw(t_cub *cub, t_map *info_map)
{
	int	x;
	int y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (info_map->map[x][y] == '1')
				coloring_pixel(cub, x, y, 0x00FF0000);
			else
				coloring_pixel(cub, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, 0, 0);
}
