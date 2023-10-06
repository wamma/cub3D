#include "../cub3D.h"

char	**parse_map(t_map *info_map)
{
	char	**map;
	char	*map_line;

	check_map_exist(info_map);
	check_map_seperate(info_map);
	get_map_size(info_map);
	check_valid_component(info_map);
	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
	map = init_ppc(info_map->width, info_map->height);
	info_map->map = get_map(info_map, map_line, map);
	check_and_get_starting_position(info_map, info_map->map);
	return (map);
}

void	check_map_exist(t_map *info_map)
{
	char	*map_line;

	map_line = get_next_line(info_map->map_path_fd);
	while (map_line != NULL)
	{
		if (is_all_white_space(map_line) == 0)
			break ;
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	if (!map_line)
		ft_error("Check : There's no map!\n");
	else
	{
		info_map->width = ft_strlen(map_line);
		free(map_line);
	}
}

void	check_map_seperate(t_map *info_map)
{
	char	*map_line;

	map_line = get_next_line(info_map->map_path_fd);
	while (map_line != NULL && is_all_white_space(map_line) == 0)
	{
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	while (map_line != NULL)
	{
		if (is_all_white_space(map_line) == 0)
		{
			free(map_line);
			ft_error("Check : map is seperated\n");
		}
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	close(info_map->map_path_fd);
}

void	get_map_size(t_map *info_map)
{
	int		h;
	char	*map_line;

	h = 0;
	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
	while (map_line != NULL && is_all_white_space(map_line) == 0)
	{
		if (ft_strlen(map_line) > info_map->width)
			info_map->width = ft_strlen(map_line);
		h++;
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	info_map->height = h;
	close(info_map->map_path_fd);
}

void	check_valid_component(t_map *info_map)
{
	int		i;
	char	*map_line;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
	while (map_line != NULL)
	{
		i = 0;
		while (map_line[i] != '\0')
		{
			if (map_line[i] != '1' && map_line[i] != '0' && \
			map_line[i] != 'N' && map_line[i] != 'S' && map_line[i] != 'E' \
			&& map_line[i] != 'W' && is_white_space(map_line[i]) == 0)
			{
				free(map_line);
				ft_error("Check: wrong component\n");
			}
			i++;
		}
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
}

char	**get_map(t_map *info_map, char *map_line, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info_map->height)
	{
		j = 0;
		while (map_line[j] != '\0' && map_line[j] != '\n')
		{
			if (map_line[j] == ' ')
				map[i][j] = UNDEFINED_MAP;
			else
				map[i][j] = map_line[j];
			j++;
		}
		while (j < (int)info_map->width -1)
		{
			map[i][j] = UNDEFINED_MAP;
			j++;
		}
		map[i][j] = '\0';
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	return (map);
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