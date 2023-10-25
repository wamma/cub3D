/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:10 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:41 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_texture_info(t_map *info_map, char *line)
{
	char	**splited;
	int		element_type;
	int		*element_cnt;

	element_cnt = init_array_zero(7);
	while (line != NULL)
	{
		splited = ft_split_white_space(line);
		element_type = get_element_type(splited);
		if (element_type >= EA_PATH && element_type <= CEILING)
			get_path_n_color(info_map, element_type, splited, element_cnt);
		if (element_cnt[SUM] == 6)
		{
			free_ppc(splited);
			break ;
		}
		free_ppc(splited);
		free(line);
		line = get_next_line(info_map->map_path_fd);
	}
	free(line);
	check_element_cnt(element_cnt, info_map);
}

void	parse_info_map(t_map *info_map, char *map_path)
{
	char	*first_line;

	check_valid_map_path(map_path);
	info_map->map_path = map_path;
	first_line = check_empty_file(info_map);
	get_texture_info(info_map, first_line);
	check_valid_texture_path(info_map);
	check_duplicated_map_path(info_map);
	info_map->map = parse_map(info_map);
}
