#include "../cub3D.h"

char	*get_starting_line_of_map(t_map *info_map)
{
	int		cnt;
	char	*map_line;

	cnt = 0;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_next_line(info_map->map_path_fd);
	while (map_line != NULL)
	{
		if (is_all_white_space(map_line) == 0)
		{
			if (cnt == 6)
				break ;
			else
				cnt++;
		}
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	return (map_line);
}

int	is_player(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	return (0);
}