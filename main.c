/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:23:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 21:31:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argc\n");
	init_info_map(argv[1], &info_map);
	check_valid_map(&info_map);
	info_map.map = parse_map(&info_map);
	free(info_map.no_path);
	return (0);
}
