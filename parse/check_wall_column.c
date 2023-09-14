#include "../cub3D.h"

int	check_wall_column(char **map, int height, int width)
{
	int	i;
	int	j;

	j = 0;
	while (j < width - 1)
	{
		i = 0;
		while (i < height)
		{
			if ((i == 0 || i == height - 1) && \
			(map[i][j] != '1' && map[i][j] != 'x'))
				return (0);
			else
			{
				if (map[i][j] == '0' || is_player(map[i][j]) == 1)
					if (map[i - 1][j] == 'x' || \
					map[i + 1][j] == 'x' || map[i + 1][j] == '\0')
						return (0);
			}	
			i++;
		}
		j++;
	}
	return (1);
}