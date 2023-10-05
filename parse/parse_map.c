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
	check_and_get_starting_position(info_map, map);
	return (map);
}

void	get_player_starting_position(t_map *info_map, int x, int y, char direc)
{
	info_map->starting_x = x;
	info_map->starting_y = y;
	info_map->starting_direction = direc;
}

void	check_and_get_starting_position(t_map *info_map, char **map)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	cnt = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if (is_player(map[i][j]) == 1)
			{
				if (cnt > 0)
					ft_error("Check : too many players\n");
				cnt++;
				get_player_starting_position(info_map, i, j, map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (cnt == 0)
		ft_error("Check : there's no player\n");
}

char	**copy_char_map(t_map *info_map)
{
	char	*map_line;
	char	**map;

	map_line = get_starting_line_of_map(info_map);
	map = get_map(info_map, map_line);
	return (map);
}
