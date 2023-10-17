#include "../cub3D.h"

void	init_buf(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	cub->buf = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
	if (!cub->buf)
		ft_error("Check: malloc");
	while (i < WIN_HEIGHT)
	{
		cub->buf[i] = (int *)malloc(sizeof(int *) * WIN_WIDTH);
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			cub->buf[i][j] = 0;
			j++;
		}
		i++;
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