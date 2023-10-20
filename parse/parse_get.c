#include "../cub3D.h"

void	get_texture_info(t_map *info_map)
{
	char	*line;
	char	**splited;
	int		element_type;
	int		*element_cnt;

	element_cnt = init_array_zero(7);
	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	line = get_next_line(info_map->map_path_fd);
	while (line != NULL)
	{
		splited = ft_split_white_space(line);
		element_type = get_element_type(splited);
		if (element_type >= EA_PATH && element_type <= CEILING)
			get_path_n_color(info_map, element_type, splited, element_cnt);
		//free_ppc(splited);
		//free(line);
		if (element_cnt[SUM] == 6)
			break;
		line = get_next_line(info_map->map_path_fd);
	}
	if (element_cnt[SUM] != 6)
		ft_error("Check : invalidate file form\n");//fd도 close
	//close(info_map->map_path_fd);
}

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

int	check_valid_rgb_element(char *rgb)
{
	int	i;
	int	flag_comma;

	i = 0;
	flag_comma = 0;
	printf("%s\n", rgb);
	while (rgb[i] != '\0')
	{
		if (ft_isdigit(rgb[i]) == 0 && is_white_space(rgb[i]) == 0 && rgb[i] != ',')
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
	return (1);
}

int	check_valid_rgb_number(char *rgb)
{
	int	i;
	int	flag;
	int	cnt;

	i = 0;
	cnt = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		ft_error("Check: invalid rgb number");
}

//123,,,
void	get_f_n_c_info(t_map *info_map, int type, char **info, int *cnt)
{
	char	**rgb;

	if (cnt[type] > 0)
		ft_error("Check: duplicated element\n");
	check_valid_rgb_element(info[1]);
	//check_valid_rgb_number(info[1]);
	rgb = ft_split(info[1], ',');
	check_valid_rgb_form(rgb);
	if (type == FLOOR)
	{
		info_map->floor->r = ft_atoi(rgb[0]);
		info_map->floor->g = ft_atoi(rgb[1]);
		info_map->floor->b = ft_atoi(rgb[2]);
	}
	else if (type == CEILING)
	{
		info_map->ceiling->r = ft_atoi(rgb[0]);
		info_map->ceiling->g = ft_atoi(rgb[1]);
		info_map->ceiling->b = ft_atoi(rgb[2]);
	}
	cnt[type]++;
	free_ppc(rgb);
}
