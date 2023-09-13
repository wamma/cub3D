#include "test.h"

int main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	check_valid_path(argv[1]);
	//init_t_map(argv[1], &info_map);
}