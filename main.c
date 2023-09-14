#include "cub3D.h"

int main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);
	//for (int i = 0; info_map.map[i] != NULL; i++)
	//{
	//	printf("%s\n", info_map.map[i]);
	//}

}