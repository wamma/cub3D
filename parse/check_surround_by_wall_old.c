#include "../cub3D.h"

int	is_empty_space(char component)
{
	if (component == 'x')
		return (TRUE);
	return (FALSE);
}

int	is_surrouned(char **map, int x, int y, t_map *map_info)
{
	if (x - 1 < 0 || is_empty_space(map[x - 1][y]) == TRUE)
	{
		return (FALSE);
	}
	if (x + 1 >= map_info->width || is_empty_space(map[x + 1][y]) == TRUE)
	{
		return (FALSE);
	}
	if (y + 1 >= map_info->height || is_empty_space(map[x][y + 1]) == TRUE)
	{
		return (FALSE);
	}
	if (y - 1 < 0 || is_empty_space(map[x][y - 1]) == TRUE)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	check_map_surrounded(char **map, t_map *map_info)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (map[x][y] == '0' && is_surrouned(map, x, y, map_info) == FALSE)
			{
				return (FALSE);
			}
			++x;
		}
		++y;
	}
	return (TRUE);
}

//int	is_all_wall_first_n_last_row(char *map_row)
//{
//	int	i;

//	i = 0;
//	while (map_row[i] != '\0')
//	{
//		if (map_row[i] != '1' && map_row[i] != 'x')
//			return (0);
//		i++;
//	}
//	return (1);
//}

//int	check_is_valid_wall_row(char *map_row)
//{
//	int	i;

//	i = 0;
//	while (map_row[i] != '\0')
//	{
//		if (map_row[i] == '0' || is_player(map_row[i]) == 1)
//		{
//			if (i != 0 && map_row[i - 1] == UNDEFINED_MAP)
//				return (0);
//			if (map_row[i + 1] == UNDEFINED_MAP || map_row[i + 1] == '\0')
//				return (0);
//		}
//		i++;
//	}
//	return (1);
//}

//int	check_wall_column(char **map, int height, int width)
//{
//	int	i;
//	int	j;

//	j = 0;
//	while (j < width - 1)
//	{
//		i = 0;
//		while (i < height)
//		{
//			if ((i == 0 || i == height - 1) && \
//			(map[i][j] != '1' && map[i][j] != 'x'))
//				return (0);
//			else
//			{
//				if (map[i][j] == '0' || is_player(map[i][j]) == 1)
//					if (map[i - 1][j] == 'x' || \
//					map[i + 1][j] == 'x' || map[i + 1][j] == '\0')
//						return (0);
//			}	
//			i++;
//		}
//		j++;
//	}
//	return (1);
//}