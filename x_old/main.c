#include "cub3D.h"

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
	free(info_map.no_path);
	return (0);
}
 