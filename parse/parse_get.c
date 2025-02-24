/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:48:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_element_type(char **info)
{
	int	type;

	type = -1;
	if (info[0] == NULL)
		type = 0;
	else if (is_same(info[0], "EA") == 1)
		type = EA_PATH;
	else if (is_same(info[0], "WE") == 1)
		type = WE_PATH;
	else if (is_same(info[0], "SO") == 1)
		type = SO_PATH;
	else if (is_same(info[0], "NO") == 1)
		type = NO_PATH;
	else if (is_same(info[0], "F") == 1)
		type = FLOOR;
	else if (is_same(info[0], "C") == 1)
		type = CEILING;
	check_valid_texture_form(type, info);
	return (type);
}

void	get_path_n_color(t_map *info_map, int type, char **info, int *cnt)
{
	if (info[1] == NULL)
		ft_error("Check : invalidate file form\n");
	if (type >= EA_PATH && type <= NO_PATH)
		get_texture_path(info_map, type, info, cnt);
	else if (type >= FLOOR && type <= CEILING)
		get_f_n_c_info(info_map, type, info, cnt);
	cnt[SUM]++;
}

void	get_texture_path(t_map *info_map, int type, char **info, int *cnt)
{
	if (cnt[type] > 0)
		ft_error("Check: duplicated element\n");
	if (type == EA_PATH)
		info_map->ea_path = ft_strdup(info[1]);
	else if (type == WE_PATH)
		info_map->we_path = ft_strdup(info[1]);
	else if (type == SO_PATH)
		info_map->so_path = ft_strdup(info[1]);
	else if (type == NO_PATH)
		info_map->no_path = ft_strdup(info[1]);
	cnt[type]++;
}

int	rgb_atoi(char *str)
{
	long	num;

	num = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > 2147483647)
		ft_error("Check: wrong rgb range\n");
	return ((int)num);
}

void	get_f_n_c_info(t_map *info_map, int type, char **info, int *cnt)
{
	char	**rgb;

	if (cnt[type] > 0)
		ft_error("Check: duplicated element\n");
	check_valid_rgb_element(info[1]);
	rgb = ft_split(info[1], ',');
	check_numbers_of_rgb(rgb);
	if (type == FLOOR)
	{
		info_map->floor->r = rgb_atoi(rgb[0]);
		info_map->floor->g = rgb_atoi(rgb[1]);
		info_map->floor->b = rgb_atoi(rgb[2]);
	}
	else if (type == CEILING)
	{
		info_map->ceiling->r = rgb_atoi(rgb[0]);
		info_map->ceiling->g = rgb_atoi(rgb[1]);
		info_map->ceiling->b = rgb_atoi(rgb[2]);
	}
	check_valid_rgb_value(info_map);
	cnt[type]++;
	free_ppc(rgb);
}
