#include "test.h"

void	get_f_n_c_info(t_map *info_map, int type, char **info, int *cnt)
{
	char	**rgb;

	if (cnt[type] > 0)
		ft_error("Check: duplicated element\n");
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
		splited = split_white_space(line);
		element_type = get_element_type(splited);
		if (element_type >= EA_PATH && element_type <= CEILING)
			get_path_n_color(info_map, element_type, splited, element_cnt);
		free_ppc(splited);
		free(line);
		if (element_cnt[SUM] == 6)
			break;
		line = get_next_line(info_map->map_path_fd);
	}
	if (element_cnt[SUM] != 6)
		ft_error("Check : invalidate file form\n");
	close(info_map->map_path_fd);
}