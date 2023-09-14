#include "../cub3D.h"

void	get_map_size(t_map *info_map)
{
	char	*map_line;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
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

char	**get_map(t_map *info_map)
{
	get_map_size(info_map);
	printf("width: %d height: %d\n", info_map->width, info_map->height);
	return (0);
}