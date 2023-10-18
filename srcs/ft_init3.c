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

void	init_texture_array(t_cub *cub)
{
	int	i;

	i = 0;
	cub->texture = (int **)malloc(sizeof(int *) * TEXTURE_NUMBER);
	if (!cub->texture)
		ft_error("Check: malloc");
	while (i < TEXTURE_NUMBER)
	{
		cub->texture[i] = (int *)malloc(sizeof(int) * (1000 * 1000));
		if (!cub->texture[i])
			ft_error("Check: malloc");
		i++;
	}
}
