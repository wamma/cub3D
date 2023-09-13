#include "test.h"

int	main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argc\n");
	init_struct(&info_map);
	init_info_map(argv[1], &info_map);
	if (check_valid_map(&info_map) != 6)
		ft_error("A component of the map is missing.\n");
	info_map.map = parse_map(&info_map);
	//printf("here\n");
	//printf("width: %d, height: %d\n", info_map.width, info_map.height);
	//for(int i = 0; i < info_map.height; i++)
	//{
	//	printf("%s\n", info_map.map[i]);
	//}
	//printf("%d %d %c\n", info_map.starting_x, info_map.starting_y, info_map.starting_direction);
	//free(info_map.no_path);
	return (0);
}
 