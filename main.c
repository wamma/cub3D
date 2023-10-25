/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:27:28 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 17:31:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	leaks_check()
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_map		info_map;
	t_cub		cub;

	atexit(leaks_check);
	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	parse_info_map(&info_map, argv[1]);
	init_mlx(&cub);
	init_s_cub(&cub, &info_map);
	load_image(&cub);
	mlx_loop_hook(cub.mlx, &main_loop, &cub);
	mlx_hook(cub.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
