/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:23:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 18:32:18 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argc\n");
	save_direction_file(argv[1], &info_map);
	printf("NO: %s\n", info_map.no_path);
	check_valid_map(&info_map);
	info_map.map_path = get_path(argv[1]);
	info_map.map = parse_map(&info_map);
	return (0);
}
