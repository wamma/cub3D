#include "../cub3D.h"

void	get_map_size(t_map *info_map)
{
	char	*map_line;

	map_line = get_starting_line_of_map(info_map);
	while (map_line != NULL && is_all_white_space(map_line) == 0)
	{
		if (ft_strlen(map_line) > info_map->width)
			info_map->width = ft_strlen(map_line) - 1;
		info_map->height++;
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	if (map_line != NULL)
		read_remain_of_map(info_map->map_path_fd, map_line);
}

char	**get_map(t_map *info_map, char *map_line)
{
	char	**map;
	int		y;
	int		x;

	map = allocate_two_dimension_array(info_map->height, info_map->width);
	y = info_map->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (map_line[x] != '\0' && map_line[x] != '\n')
		{
			if (is_white_space(map_line[x]) == 1)
				map[y][x] = 'x';
			else
				map[y][x] = map_line[x];
			++x;
		}
		while (x < info_map->width)
		{
			map[y][x] = 'x';
			++x;
		}
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
		--y;
	}
	free(map_line);
	return (map);
}

/*
char	**get_map(t_map *info_map, char *map_line)
{
	char	**map;
	int		i;
	int		j;

	printf("width: %d, height: %d\n", info_map->width, info_map->height);
	map = allocate_two_dimension_array(info_map->height, info_map->width - 1);
	i = info_map->height;
	while (i >= 0)
	{
		j = 0;
		while (map_line[j] != '\0' && map_line[j] != '\n')
		{
			if (is_white_space(map_line[j]) == 1)
				map[i][j] = 'x';
			else
				map[i][j] = map_line[j];
			j++;
		}
		while (j < info_map->width - 1)
		{
			map[i][j] = 'x';
			j++;
		}
		map_line = get_next_line(info_map->map_path_fd);
		i--;
	}
	//printf("map\n");
	//for(int i = 0; map[i] != NULL; i++)
	//{
	//	//printf("i = %d\n", i);
	//	for(int j = 0; map[i][j] != '\0'; j++)
	//	{
	//		printf("%c", map[i][j]);
	//	}
	//	printf(".\n");
	//}
	return (map);
}
*/
/*
char	**get_map(t_map *info_map, char *map_line)
{
	char	**map;
	int		i;
	int		j;

	// printf("width: %d, height: %d\n", info_map->width, info_map->height);
	map = allocate_two_dimension_array(info_map->height, info_map->width - 1);
	i = 0;
	while (i < info_map->height)
	{
		j = 0;
		while (map_line[j] != '\0' && map_line[j] != '\n')
		{
			if (is_white_space(map_line[j]) == 1)
				map[i][j] = 'x';
			else
				map[i][j] = map_line[j];
			j++;
		}
		while (j < info_map->width - 1)
		{
			map[i][j] = 'x';
			j++;
		}
		map_line = get_next_line(info_map->map_path_fd);
		i++;
	}
	//printf("map\n");
	//for(int i = 0; map[i] != NULL; i++)
	//{
	//	//printf("i = %d\n", i);
	//	for(int j = 0; map[i][j] != '\0'; j++)
	//	{
	//		printf("%c", map[i][j]);
	//	}
	//	printf(".\n");
	//}
	return (map);
}
*/