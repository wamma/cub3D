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

void	print_struct_camera(t_camera *camera)
{
	printf("dir: %f, %f\n", camera->dir.x, camera->dir.y);
	printf("plane: %f, %f\n", camera->plane.x, camera->plane.y);
	printf("pos: %f, %f\n", camera->pos.x, camera->pos.y);
	printf("fov: %f\n", camera->fov);
	printf("rotation: %f\n", camera->rotation);
}

int	main(int argc, char **argv)
{
	t_map		info_map;
	t_cub		cub;
	t_camera	camera;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);
	init_s_cub(&cub);
	init_s_camera(&camera, &info_map);
	// print_struct_map(&info_map);
	// print_struct_camera(&camera);
	draw(&cub, &info_map);
	mlx_loop(cub.mlx);
	return (0);
}
