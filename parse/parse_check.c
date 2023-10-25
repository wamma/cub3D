/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:03 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:44 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*check_empty_file(t_map *info_map)
{
	char	*line;

	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	line = get_next_line(info_map->map_path_fd);
	if (line == NULL)
		ft_error("Check: empty file");
	return (line);
}

char	**get_map_path_2d_array(t_map *info_map)
{
	char	**map_path;
	int		i;

	map_path = (char **)malloc(sizeof(char *) * 5);
	if (map_path == NULL)
		ft_error("malloc error");
	map_path[4] = NULL;
	i = 0;
	while (i < 4)
	{
		if (i == 0)
			map_path[i] = ft_strdup(info_map->ea_path);
		else if (i == 1)
			map_path[i] = ft_strdup(info_map->we_path);
		else if (i == 2)
			map_path[i] = ft_strdup(info_map->so_path);
		else if (i == 3)
			map_path[i] = ft_strdup(info_map->no_path);
		i++;
	}
	return (map_path);
}

void	check_duplicated_map_path(t_map *info_map)
{
	char	**map_path;
	int		i;
	int		j;

	map_path = get_map_path_2d_array(info_map);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j)
			{
				if (ft_strncmp(map_path[i], map_path[j], \
				ft_strlen(map_path[i])) == 0)
				{
					free_two_dimension_array(map_path);
					ft_error_free_map("Check : use different texture path\n", \
					info_map);
				}
			}
		}
	}
	free_two_dimension_array(map_path);
}

void	check_element_cnt(int *element_cnt, t_map *info_map)
{
	if (element_cnt[SUM] != 6)
	{
		free(element_cnt);
		close (info_map->map_path_fd);
		ft_error_free_map("Check : numbers of element\n", info_map);
	}
	free(element_cnt);
}

void	check_valid_texture_path(t_map *info_map)
{
	int	fd;

	fd = open(info_map->no_path, O_RDONLY);
	if (fd < 0)
		ft_error_free_map("Check: invalid texture path\n", info_map);
	close(fd);
	fd = open(info_map->so_path, O_RDONLY);
	if (fd < 0)
		ft_error_free_map("Check: invalid texture path\n", info_map);
	close(fd);
	fd = open(info_map->we_path, O_RDONLY);
	if (fd < 0)
		ft_error_free_map("Check: invalid texture path\n", info_map);
	close(fd);
	fd = open(info_map->ea_path, O_RDONLY);
	if (fd < 0)
		ft_error_free_map("Check: invalid texture path\n", info_map);
	close(fd);
}
