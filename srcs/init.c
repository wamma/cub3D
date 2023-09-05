/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:44:28 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 21:31:42 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

void	init_info_map(char *map_name, t_map *info_map)
{
	int		fd;
	char	*line;
	int		n_path_count;
	int		s_path_count;
	int		w_path_count;
	int		e_path_count;

	n_path_count = 0;
	s_path_count = 0;
	w_path_count = 0;
	e_path_count = 0;
	check_extension(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Check: map path\n");
	info_map->map_path = map_name;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (n_path_count > 0)
				ft_error("Duplicate texture path");
			info_map->no_path = ft_after_space(line);
			n_path_count++;
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (s_path_count > 0)
				ft_error("Duplicate texture path");
			info_map->so_path = ft_after_space(line);
			s_path_count++;
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (w_path_count > 0)
				ft_error("Duplicate texture path");
			info_map->we_path = ft_after_space(line);
			w_path_count++;
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (e_path_count > 0)
				ft_error("Duplicate texture path");
			info_map->ea_path = ft_after_space(line);
			e_path_count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
