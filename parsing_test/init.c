#include "test.h"


init_t_element_cnt(t_element_cnt *cnt)
{
	ft_memset(cnt, 0, sizeof(t_element_cnt));
	cnt->no_texture = 0;
	cnt->so_texture = 0;
	cnt->we_texture = 0;
	cnt->ea_texture = 0;
	cnt->floor = 0;
	cnt->ceiling = 0;
}

void	get_texture_path(t_map *info_map)
{
	char			*line;
	t_element_cnt	cnt;

	init_t_element_cnt(&cnt);
	info_map->map_path_fd = open(info_map->map_path, O_RDONLY);
	line = get_next_line(info_map->map_path_fd);
	while (line != NULL)
	{
		if (check_texture_path() == NO_PATH)

	}
}

void	init_floor_and_ceiling_structure(t_map *info_map)
{

	info_map->floor = malloc(sizeof(t_rgb));
	if (!info_map->floor)
		ft_error("Failed malloc\n");
	ft_memset(info_map->floor, 0, sizeof(t_rgb));
	info_map->ceiling = malloc(sizeof(t_rgb));
	if (!info_map->ceiling)
		ft_error("Failed malloc\n");
	ft_memset(info_map->ceiling, 0, sizeof(t_rgb));
}

void	init_t_map(char *map_path, t_map *info_map)
{
	ft_memset(info_map, 0, sizeof(t_map));
	init_floor_and_ceiling_structure(info_map);
	info_map->map_path = map_path;
	check_and_get_texture_path(info_map);
}