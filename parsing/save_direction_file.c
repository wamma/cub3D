/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_direction_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:15:27 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 18:38:37 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*ft_after_space(char *str)
{
	while (*str && *str != ' ')
		str++;
	if (*str == ' ')
		str++;
	return (ft_strdup(str));
}

void	init_info_map(t_map *info_map)
{
	info_map->no_path = NULL;
	info_map->so_path = NULL;
	info_map->we_path = NULL;
	info_map->ea_path = NULL;
}

void	save_direction_file(char *map_name, t_map *info_map)
{
	int		fd;
	char	*line;
	char	*temp;

	init_info_map(info_map);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Check: map path\n");
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			temp = ft_after_space(line);
			free(info_map->no_path);
			info_map->no_path = temp;
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			temp = ft_after_space(line);
			free(info_map->so_path);
			info_map->so_path = temp;
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			temp = ft_after_space(line);
			free(info_map->we_path);
			info_map->we_path = temp;
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			temp = ft_after_space(line);
			free(info_map->ea_path);
			info_map->ea_path = temp;
		}
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
