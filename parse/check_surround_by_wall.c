/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround_by_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:24:53 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 20:31:05 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_all_direction(char **map, int y, int x)
{
	if (map[y + 1][x] == 'x')
		return (FALSE);
	if (map[y - 1][x] == 'x')
		return (FALSE);
	if (x - 1 < 0)
		return (FALSE);
	if (map[y][x - 1] == 'x')
		return (FALSE);
	if (map[y][x + 1] == 'x' || map[y][x + 1] == '\0')
		return (FALSE);
	return (TRUE);
}

int	check_surrounded_by_wall(char **map, t_map *info_map)
{
	int	y;
	int	x;

	y = info_map->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x <= info_map->width - 1)
		{
			if (y == info_map->height - 1 || y == 0)
			{
				if (map[y][x] != '1' && map[y][x] != 'x')
					return (FALSE);
			}
			else
			{
				if (map[y][x] == '0' || is_player(map[y][x]) == 1)
				{
					if (check_all_direction(map, y, x) == FALSE)
						return (FALSE);
				}
			}
		}
	}
	return (TRUE);
}
