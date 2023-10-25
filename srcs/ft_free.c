/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 14:27:08 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_ppc(char **ppc)
{
	int	i;

	i = 0;
	while (ppc[i] != NULL)
	{
		free(ppc[i]);
		ppc[i] = NULL;
		i++;
	}
	free(ppc);
	ppc = NULL;
}

void	free_s_map(t_map *map)
{
	if (map->no_path != NULL)
		free(map->no_path);
	if (map->so_path != NULL)
		free(map->so_path);
	if (map->we_path != NULL)
		free(map->we_path);
	if (map->ea_path != NULL)
		free(map->ea_path);
	free(map->floor);
	free(map->ceiling);
}