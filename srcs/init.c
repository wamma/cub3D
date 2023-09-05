/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:44:28 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 20:16:03 by eoh              ###   ########.fr       */
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

	check_extension(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Check: map path\n");
	info_map->map_path = map_name;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			info_map->no_path = ft_after_space(line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			info_map->so_path = ft_after_space(line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			info_map->we_path = ft_after_space(line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			info_map->ea_path = ft_after_space(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}//NO가 두번 들어올경우 개행을 잘라서 
// open으로 경로 유효성검사
