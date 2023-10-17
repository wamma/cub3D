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
			//mlx_pixel_put(cub->mlx, cub->win, x, y, cub->);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, x, y);
			y++;
		}
		x++;
	}
}

int	main_loop(t_cub *cub)
{
	calculate(cub);
	// draw(cub);
	return (0);
}
