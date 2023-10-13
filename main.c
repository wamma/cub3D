#include "cub3D.h"

void	print_struct_map(t_map *map)
{
	for (int i = 0; map->map[i] != NULL; i++)
		printf("%s\n", map->map[i]);
	printf("map_path: %s\n", map->map_path);
	printf("no_path: %s\n", map->no_path);
	printf("so_path: %s\n", map->so_path);
	printf("we_path: %s\n", map->we_path);
	printf("ea_path: %s\n", map->ea_path);
	printf("floor: %d, %d, %d\n", map->floor->r, map->floor->g, map->floor->b);
	printf("ceiling: %d, %d, %d\n", map->ceiling->r, map->ceiling->g, map->ceiling->b);
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
	printf("starting_x: %f\n", map->starting_x);
	printf("starting_y: %f\n", map->starting_y);
	printf("starting_direction: %d\n", map->starting_direction);
}

void	print_struct_camera(t_cub *cub)
{
	printf("dir: %f, %f\n", cub->dir.x, cub->dir.y);
	printf("plane: %f, %f\n", cub->plane.x, cub->plane.y);
	printf("pos: %f, %f\n", cub->pos.x, cub->pos.y);
	printf("move_speed: %f\n", cub->move_speed);
	printf("rot_speed: %f\n", cub->rot_speed);
}

int	main(int argc, char **argv)
{
	t_map		info_map;
	t_cub		cub;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);
	init_mlx(&cub);
	init_s_cub(&cub, &info_map);
	load_image(&cub);
	// mlx_loop_hook(cub.mlx, &main_loop, &cub);
	// mlx_hook(cub.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	// mlx_loop(cub.mlx);
	// print_struct_map(&info_map);
	// print_struct_camera(&camera);
	return (0);
}
