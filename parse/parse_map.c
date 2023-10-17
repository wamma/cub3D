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
	for(int i = info_map->height - 1; i >= 0; i--)
	{
		for (int j = 0; j < info_map->width; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	if (check_surrounded_by_wall(map, info_map) == FALSE)
		ft_error("Check: map isn't surrounded by wall\n");

	//if (check_wall_row(map, info_map->height) == 0)
	//	ft_error("Check: map isn't surrounded by wall\n");
	//if (check_wall_column(map, info_map->height, info_map->width) == 0)
	//	ft_error("Check: map isn't surrounded by wall\n");
	check_and_get_starting_position(info_map, map);
	return (map);
}

void	get_player_starting_position(t_map *info_map, int y, int x, char direc)
{
	info_map->starting_x = x;
	info_map->starting_y = y;
	info_map->starting_direction = direc;
}

void	check_and_get_starting_position(t_map *info_map, char **map)
{
	int		y;
	int		x;
	int		cnt;

	y = 0;
	cnt = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while(map[y][x] != '\0')
		{
			if (is_player(map[y][x]) == 1)
			{
				if (cnt > 0)
					ft_error("Check : too many players\n");
				cnt++;
				get_player_starting_position(info_map, y, x, map[y][x]);
			}
			x++;
		}
		y++;
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
