#include "cub3D.h"

void	foo(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_map		info_map;
	t_cub		cub;

	// atexit(foo);
	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);
	init_mlx(&cub);
	init_s_cub(&cub, &info_map);
	load_image(&cub);
	main_loop(&cub);
	//mlx_loop_hook(cub.mlx, &main_loop, &cub);
	mlx_hook(cub.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
