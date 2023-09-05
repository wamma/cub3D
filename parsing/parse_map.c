/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:21:36 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 17:31:48 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**parse_map(t_map *info_map)
{
	char	**map;

	check_map_exist(info_map);
	get_map_size(info_map);
	check_valid_component(info_map);
	map = get_map(info_map);
	return (map);
}

void	check_map_exist(t_map *info_map)
{
	char	*map_line;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
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

void	get_map_size(t_map *info_map)
{
	int		h;
	char	*map_line;

	h = 1;
	map_line = get_next_line(info_map->map_path_fd);
	while (map_line)
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

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	check_valid_component(t_map *info_map)
{
	int		i;
	int		cnt;
	char	*map_line;

	cnt = 0;
	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
	while (map_line != NULL)
	{
		i = 0;
		while (map_line[i])
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
		//free(map_line);->왜 더블프리?
		map_line = get_next_line(info_map->map_path_fd);
		cnt++;
	}
	close(info_map->map_path_fd);
}

char	**get_map(t_map *info_map)
{
	char	*map_line;
	char	**map;
	int		i;
	int		j;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	map_line = get_starting_line_of_map(info_map->map_path_fd);
	map = init_ppc(info_map->width, info_map->height);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map_line[j] != '\0')
		{
			map[i][j] = map_line[j];
			j++;
		}
		while (map[i][j] != '\0')
		{
			map[i][j] = UNDEFINED_MAP;
			j++;
		}
		i++;
	}
	return (map);
}
