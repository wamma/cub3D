/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:48:19 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 20:49:11 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_direction(t_map *map)
{
	free(map->no_path);
	free(map->so_path);
	free(map->ea_path);
	free(map->we_path);
}