/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:01 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:42:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_map_component(t_map *info_map)
{
	char	*map_line;

	map_line = get_next_line(info_map->map_path_fd);
	while (is_all_white_space(map_line) == 1)
	{
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	while (map_line != NULL)
	{
		if (is_all_white_space(map_line) == 1)
			break ;
		check_valid_map_component(map_line, info_map);
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
	if (map_line != NULL)
		check_map_seperated(info_map, map_line);
	close(info_map->map_path_fd);
}

void	check_valid_map_component(char *line, t_map *info_map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' \
		&& is_player(line[i]) != 1 && is_white_space(line[i]) != 1)
		{
			free(line);
			free_s_map(info_map);
			ft_error("Check: invalid map component\n");
		}
		i++;
	}
}

void	check_map_seperated(t_map *info_map, char *map_line)
{
	if (map_line != NULL)
		free(map_line);
	map_line = get_next_line(info_map->map_path_fd);
	while (map_line != NULL)
	{
		if (is_all_white_space(map_line) != 1)
		{
			free(map_line);
			free_s_map(info_map);
			ft_error("Check: map is seperated\n");
		}
		free(map_line);
		map_line = get_next_line(info_map->map_path_fd);
	}
}
