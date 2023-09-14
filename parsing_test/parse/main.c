#include "test.h"

int main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);

}