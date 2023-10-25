/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 17:08:39 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	fill_map_line(char **map, char *map_line, int y, t_map *info_map)
{
	int	x;

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
}

char	**get_map(t_map *info_map, char *map_line)
{
	char	**map;
	int		y;

	map = allocate_two_dimension_array(info_map->height, info_map->width);
	y = info_map->height - 1;
	while (y >= 0)
	{
		fill_map_line(map, map_line, y, info_map);
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
		--y;
	}
	free(map_line);
	return (map);
}
