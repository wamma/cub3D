#include "../cub3D.h"

int	check_wall_row(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			if (is_all_wall_first_n_last_row(map[i]) == 0)
				return (0);
		}
		else
		{
			if (check_is_valid_wall_row(map[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_wall_first_n_last_row(char *map_row)
{
	int	i;

	i = 0;
	while (map_row[i] != '\0')
	{
		if (map_row[i] != '1' && map_row[i] != 'x')
			return (0);
		i++;
	}
	return (1);
}

int	check_is_valid_wall_row(char *map_row)
{
	int	i;

	i = 0;
	while (map_row[i] != '\0')
	{
		if (map_row[i] == '0' || is_player(map_row[i]) == 1)
		{
			if (i != 0 && map_row[i - 1] == UNDEFINED_MAP)
				return (0);
			if (map_row[i + 1] == UNDEFINED_MAP || map_row[i + 1] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
