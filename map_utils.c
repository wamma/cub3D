/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:15 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 14:02:54 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_starting_line_of_map(int fd)
{
	int		cnt;
	char	*map_line;

	cnt = 0;
	map_line = get_next_line(fd);
	while(map_line)
	{
		if (is_all_white_space(map_line) == 0)
		{
			if (cnt == 6)
				break;
			else
				cnt++;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (map_line);
}
