#include "../cub3D.h"

void	get_map_size(t_map *info_map)
{
	char	*map_line;

	map_line = get_starting_line_of_map(info_map);
	while (map_line != NULL && is_all_white_space(map_line) == 0)
	{
		if (ft_strlen(map_line) > info_map->width)
			info_map->width = ft_strlen(map_line);
		info_map->height++;
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	if (map_line != NULL)
		read_remain_of_map(info_map->map_path_fd, map_line);
	close(info_map->map_path_fd);
}

//char	**get_map(t_map *info_map)
//{
	
//	return (0);
//}