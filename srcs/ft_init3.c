#include "../cub3D.h"

void	init_buf(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	cub->buf = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
	if (!cub->buf)
		ft_error("Check: malloc");
	while (y < WIN_HEIGHT)
	{
		cub->buf[y] = (int *)malloc(sizeof(int *) * WIN_WIDTH);
		x = 0;
		while (x < WIN_WIDTH)
		{
			cub->buf[y][x] = 0;
			x++;
		}
		y++;
	}
}
