#include "../cub3D.h"

int	check_last_map(char *line)
{
	if (is_all_white_space(line) == 1)
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || \
	ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 || \
	ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

void	check_direction(t_map *map_info)
{
	int	fd;

	fd = open(map_info->no_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: north texture path\n");
	//free하고 error출력하는 함수 새로 만들기
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

static void	input_f_c(t_map *map_info, int flag, char *line)
{
	char	**rgb;

	rgb = ft_split(line + 2, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_error("Invalid color format\n");
		return ;
	}
	if (flag == 1)
	{
		map_info->floor->r = ft_atoi(rgb[0]);
		map_info->floor->g = ft_atoi(rgb[1]);
		map_info->floor->b = ft_atoi(rgb[2]);
		if (map_info->floor->r < 0 || map_info->floor->r > 255 || \
		map_info->floor->g < 0 || map_info->floor->g > 255 || \
		map_info->floor->b < 0 || map_info->floor->b > 255)
			f_c_free_and_error(map_info, rgb);
	}
	else if (flag == 2)
	{
		map_info->ceiling->r = ft_atoi(rgb[0]);
		map_info->ceiling->g = ft_atoi(rgb[1]);
		map_info->ceiling->b = ft_atoi(rgb[2]);
		if (map_info->ceiling->r < 0 || map_info->ceiling->r > 255 || \
		map_info->ceiling->g < 0 || map_info->ceiling->g > 255 || \
		map_info->ceiling->b < 0 || map_info->ceiling->b > 255)
			f_c_free_and_error(map_info, rgb);
	}
}

void	check_f_c(t_map *map_info, char *line)
{
	int		flag;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		flag = 1;
		input_f_c(map_info, flag, line);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		flag = 2;
		input_f_c(map_info, flag, line);
	}
	
}

int	check_valid_map(t_map *map_info)
{
	char	*line;
	int		count;

	count = 0;
	map_info->map_path_fd = open(map_info->map_path, O_RDONLY);
	line = get_next_line(map_info->map_path_fd);
	while (line)
	{
		if (check_last_map(line) == 0)
			ft_error("Check : invalidate file form\n");
		check_direction(map_info);
		check_f_c(map_info, line);
		if (is_all_white_space(line) == 0)
			count++;
		free(line);
		if (count == 6)
			break ;

		line = get_next_line(map_info->map_path_fd);
	}
	return (count);
}
