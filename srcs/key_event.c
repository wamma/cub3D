#include "../cub3D.h"

int	key_press(int key_code, t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key_code == KEY_W)
	{
		if (!cub->map[(int)(cub->pos.x + cub->dir.x * cub->move_speed)][(int)(cub->pos.y)])
			cub->pos.x += cub->dir.x * cub->move_speed;
		if (!cub->map[(int)(cub->pos.x)][(int)(cub->pos.y + cub->dir.y * cub->move_speed)])
			cub->pos.y += cub->dir.y * cub->move_speed;
	}
	else if (key_code == KEY_A)
	{
		old_dir_x = cub->dir.x;
		cub->dir.x = cub->dir.x * cos(cub->rot_speed) - cub->dir.y * sin(cub->rot_speed);
		cub->dir.y = old_dir_x * sin(cub->rot_speed) + cub->dir.y * cos(cub->rot_speed);
		old_plane_x = cub->plane.x;
		cub->plane.x = cub->plane.x * cos(cub->rot_speed) - cub->plane.y * sin(cub->rot_speed);
		cub->plane.y = old_plane_x * sin(cub->rot_speed) + cub->plane.y * cos(cub->rot_speed);
	}
	else if (key_code == KEY_S)
	{
		if (!cub->map[(int)(cub->pos.x - cub->dir.x * cub->move_speed)][(int)cub->pos.y])
			cub->pos.x -= cub->dir.x * cub->move_speed;
		if (!cub->map[(int)cub->pos.x][(int)(cub->pos.y - cub->dir.y * cub->move_speed)])
			cub->pos.y -= cub->dir.y * cub->move_speed;
	}
	else if (key_code == KEY_D)
	{
		old_dir_x = cub->dir.x;
		cub->dir.x = cub->dir.x * cos(-cub->rot_speed) - cub->dir.y * sin(-cub->rot_speed);
		cub->dir.y = old_dir_x * sin(-cub->rot_speed) + cub->dir.y * cos(-cub->rot_speed);
		old_plane_x = cub->plane.x;
		cub->plane.x = cub->plane.x * cos(-cub->rot_speed) - cub->plane.y * sin(-cub->rot_speed);
		cub->plane.y = old_plane_x * sin(-cub->rot_speed) + cub->plane.y * cos(-cub->rot_speed);
	}
	else if (key_code == KEY_ESC)
		exit(0);
	mlx_clear_window(cub->mlx, cub->win);
	main_loop(cub);
	return (0);
}