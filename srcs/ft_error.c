/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 14:27:06 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}

//void	f_c_free_and_error(t_map *map_info, char **rgb)
//{
//	int	i;

//	i = -1;
//	while (++i < 3)
//		free(rgb[i]);
//	free(rgb);
//	free_direction(map_info);
//	ft_error("Check: rgb range\n");
//}
