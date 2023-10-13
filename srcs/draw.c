#include "../cub3D.h"

void	ver_line(t_cub *cub, int x, int draw_start, int draw_end, int color)
{
	int y;

	y = draw_start;
	while (y <= draw_end)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}

void	render_color(t_calc *calc, t_cub *cub)
{
	if (cub->map[calc->map_x][calc->map_y] == 1)
		calc->color = 0xFF0000;
	else
		calc->color = 0xFFFF00; // yellow
	if (calc->side == 1)
		calc->color = calc->color / 2; // green
}

int	main_loop(t_cub *cub)
{
	calc(cub);
	return (0);
}
