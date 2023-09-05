/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:44:28 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 15:06:02 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**init_ppc(int x, int y) // ppc = pointer pointer character
{
	int			i;
	char	**ppc;

	i = 0;
	ppc = (char **)malloc(sizeof(char) * (x + 1));
	ppc[x] = NULL;
	while (i < x)
	{
		ppc[i] = (char *)malloc(sizeof(char) * (y + 1));
		ppc[i][y] = '\0';
		i++;
	}
	return (ppc);
}