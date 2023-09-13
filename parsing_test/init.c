#include "test.h"

int	*init_array_zero(int size)
{
	int i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
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

void	init_s_map(char *map_path, t_map *info_map)
{
	ft_memset(info_map, 0, sizeof(t_map));
	init_floor_and_ceiling_structure(info_map);
	info_map->map_path = map_path;
	get_texture_info(info_map);
}