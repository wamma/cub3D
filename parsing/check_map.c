/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:54:27 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 17:45:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
1.맵이 가장 마지막에 위치
2. 다른 구성요소는 순서 상관 없이 위치
3. 다른 구성요소 사이에 개행이 들어가도 됨
4. 화면 크기는 우리가 정하기 나름
5. 동, 서, 남, 북 텍스쳐는 open으로 유효성 검사
6. 바닥, 천장 색상은 R, G, B 형식으로 0 ~ 255
7. 정보는 하나 이상의 공백으로 구분 될 수 있다.*/

int	check_last_map(char *line)
{
	if (is_all_white_space(line) )
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || \
	ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 || \
	ft_strncmp(line, "F ", 2) == 0 || 	ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

void	check_direction(t_map *map_info)
{
	int	fd;

	fd = open(map_info->no_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: north texture path\n");
	close(fd);
	fd = open(map_info->so_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: south texture path\n");
	close(fd);
	fd = open(map_info->we_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: west texture path\n");
	close(fd);
	fd = open(map_info->ea_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: east texture path\n");
	close(fd);
}

void	check_f_c(t_map *map_info, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (map_info->floor->r < 0 || map_info->floor->r > 255 || \
		map_info->floor->g < 0 || map_info->floor->g > 255 || \
		map_info->floor->b < 0 || map_info->floor->b > 255)
			ft_error("Check: floor rgb range\n");
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
			if (map_info->ceiling->r < 0 || map_info->ceiling->r > 255 || \
		map_info->ceiling->g < 0 || map_info->ceiling->g > 255 || \
		map_info->ceiling->b < 0 || map_info->ceiling->b > 255)
			ft_error("Check: ceiling rgb range\n");
	}
}

void	check_valid_map(t_map *map_info)
{
	char	*line;
	int		count;

	count = 0;
	map_info->fd = open(map_info->map_path, O_RDONLY);
	line = get_next_line(map_info->fd);
	while (line)
	{
		check_last_map(line); // 공백만 있거나, 6개의 형식이면 다음 라인으로 넘어감
		check_direction(map_info);
		check_f_c(map_info, line);
		free(line);
		if (count == 6)
			break ;
		line = get_next_line(map_info->fd);
		count++;
	}
	return ;
}
