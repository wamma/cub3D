#include "test.h"

char	**init_ppc(int width, int height)
{
	int			i;
	char		**ppc;

	i = 0;
	ppc = (char **)malloc(sizeof(char *) * (height + 1));
	ppc[height] = NULL;
	while (i < height)
	{
		ppc[i] = (char *)malloc(sizeof(char) * (width + 1));
		ppc[i][width] = '\0';
		i++;
	}
	return (ppc);
}

void	init_ns_texture_path(t_map *info_map, char *line)
{
	int	n_path_count;
	int	s_path_count;

	n_path_count = 0;
	s_path_count = 0;
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
}

void	init_we_texture_path(t_map *info_map, char *line)
{
	int	w_path_count;
	int	e_path_count;

	w_path_count = 0;
	e_path_count = 0;
	if (ft_strncmp(line, "WE ", 3) == 0)
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
		init_ns_texture_path(info_map, line);
		init_we_texture_path(info_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_struct(t_map *info_map)
{
	ft_memset(info_map, 0, sizeof(t_map));
	info_map->floor = malloc(sizeof(t_rgb));
	if (!info_map->floor)
		ft_error("Failed malloc\n");
	ft_memset(info_map->floor, 0, sizeof(t_rgb));
	info_map->ceiling = malloc(sizeof(t_rgb));
	if (!info_map->ceiling)
		ft_error("Failed malloc\n");
	ft_memset(info_map->ceiling, 0, sizeof(t_rgb));
}
