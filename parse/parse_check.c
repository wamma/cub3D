#include "../cub3D.h"

void	check_valid_map_path(char *argv)
{
	int	fd;

	if (rev_strncmp(argv, "buc.", 4) == -1)
		ft_error("Check: invalid map extension\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid map path\n");
	close(fd);
}


void	check_valid_texture_form(int type, char **info)
{
	int	i;

	i = 0;
	if (type == -1)
		ft_error("Check : invalidate file form\n");
	if (type >= EA_PATH && type <= CEILING)
	{
		while (info[i] != NULL)
		{
			i++;
		}
		if (i != 2)
			ft_error("Check : invalidate file form\n");
	}

}

void	check_valid_rgb_element(char *rgb)
{
	int	i;
	int	flag_comma;

	i = 0;
	flag_comma = 0;
	printf("%s\n", rgb);
	while (rgb[i] != '\0')
	{
		if (ft_isdigit(rgb[i]) == 0 && rgb[i] != ',')
			ft_error("Check: invalid rgb element\n");
		if (rgb[i] == ',')
		{
			if (flag_comma == 1)
				ft_error("Check: invalid rgb form\n");
			flag_comma = 1;
		}
		if (flag_comma == 1 && ft_isdigit(rgb[i]) == 1)
			flag_comma = 0;
		i++;
	}
	if (flag_comma == 1)
			ft_error("Check: invalid rgb form\n");
}

void	check_numbers_of_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != NULL)
	{
		i++;
	}
	if (i != 3)
		ft_error("Check : numbers of rgb\n");
}

void	free_two_dimension_array(char **arr)
{
	int	i;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
		if (i == EA_PATH)
			map_path[i] = ft_strdup(info_map->ea_path);
		else if (i == WE_PATH)
			map_path[i] = ft_strdup(info_map->we_path);
		else if (i == SO_PATH)
			map_path[i] = ft_strdup(info_map->we_path);
		else if (i == WE_PATH)
			map_path[i] = ft_strdup(info_map->we_path);
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
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				j++;
			//if (ft_strncmp(map_path[i], map_path[j], ft_strlen(map_path[i])) == 0)
			//	ft_error("Check : use different texture path\n");
			j++;
		}
		i++;
	}
	free_two_dimension_array(map_path);
}

void	check_valid_texture_path(t_map *info_map)
{
	int	fd;

	fd = open(info_map->no_path, O_RDONLY);
	if (fd < 0)
	{
		/*free_info_map(info_map, "Check: invalid texture path\n");나중에 이렇게 free랑 합치기*/
		ft_error("Check: invalid texture path\n");
	}
	close(fd);
	fd = open(info_map->so_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
	fd = open(info_map->we_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
	fd = open(info_map->ea_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
}

void	check_valid_rgb_value(t_map *info_map)
{
	if (info_map->floor->r < 0 || info_map->floor->r > 255 \
	|| info_map->floor->g < 0 || info_map->floor->g > 255 \
	|| info_map->floor->b < 0 || info_map->floor->b > 255)
		ft_error("Check: invalid color range");
	if (info_map->ceiling->r < 0 || info_map->ceiling->r > 255 \
	|| info_map->ceiling->g < 0 || info_map->ceiling->g > 255 \
	|| info_map->ceiling->b < 0 || info_map->ceiling->b > 255)
		ft_error("Check: invalid color range");
}
