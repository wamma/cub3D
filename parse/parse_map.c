/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:17 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 20:18:34 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (check_surrounded_by_wall(map, info_map) == FALSE)
		ft_error_free_map("Check: map isn't surrounded by wall\n", info_map);
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
		while (map[y][x] != '\0')
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
