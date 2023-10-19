#include "../cub3D.h"

void	draw(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			//cub->img->data_ptr[y * WIN_HEIGHT + x] = cub->buf[y][x];
			//mlx_pixel_put(cub->mlx, cub->win, x, y, cub->);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img_ptr, x, y);
			x++;
		}
		y++;
	}
}

int	main_loop(t_cub *cub)
{
	calculate(cub);
	//draw(cub);
	return (0);
}
