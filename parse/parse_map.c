#include "../cub3D.h"

char	**parse_map(t_map *info_map)
{
	char	*map_line;
	char	**map;

	check_map_component(info_map);
	get_map_size(info_map);
	map_line = get_starting_line_of_map(info_map); 
	map = get_map(info_map, map_line);
	close(info_map->map_path_fd);
	if (check_wall_row(map, info_map->height) == 0)
		ft_error("Check: map isn't surrounded by wall\n");
	if (check_wall_column(map, info_map->height, info_map->width) == 0)
		ft_error("Check: map isn't surrounded by wall\n");
	return (map);
}