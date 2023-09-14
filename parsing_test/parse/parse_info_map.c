#include "test.h"

void	parse_info_map(t_map *info_map, char *map_path)
{
	check_valid_map_path(map_path);
	info_map->map_path = map_path;
	get_texture_info(info_map);
	check_valid_texture_path(info_map);
	check_valid_rgb_value(info_map);
}