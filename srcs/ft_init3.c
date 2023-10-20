#include "../cub3D.h"

void	init_buf(t_cub *cub)
{
	int	y;

	y = 0;
	cub->buf = (int *)malloc(sizeof(int) * WIN_HEIGHT);
	while (y < WIN_HEIGHT)
	{
		cub->buf[y] = 0;
		y++;
	}
}
