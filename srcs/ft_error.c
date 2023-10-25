/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:53:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_error_free_map(char *str, t_map *info_map)
{
	free_s_map(info_map);
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}
