#include "../cub3D.h"

char	**init_ppc(int column, int row)
{
	char	**ppc;
	int		i;

	i = 0;
	ppc = (char **)malloc(sizeof(char *) * (column + 1));
	if (ppc == NULL)
		ft_error("malloc error\n");
	ppc[column] = NULL;
	while (i < column)
	{
		ppc[i] = (char *)malloc(sizeof(char) * (row + 1));
		if (ppc[i] == NULL)
			ft_error("malloc error\n");
		ppc[i][row] = '\0';
		i++;
	}
	return (ppc);
}

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

void	init_s_map(t_map *info_map)
{
	ft_memset(info_map, 0, sizeof(t_map));
	init_floor_and_ceiling_structure(info_map);
	info_map->map = NULL;
	info_map->map_path = NULL;
	info_map->no_path = NULL;
	info_map->so_path = NULL;
	info_map->we_path = NULL;
	info_map->ea_path = NULL;
	info_map->map_path_fd = 0;
	info_map->width = 0;
	info_map->height = 0;
	info_map->starting_x = 0;
	info_map->starting_y = 0;
	info_map->starting_direction = 0;
}