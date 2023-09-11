#include "test.h"

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}

void	f_c_free_and_error(t_map *map_info, char **rgb)
{
	int	i;

	i = -1;
	while (++i < 3)
		free(rgb[i]);
	free(rgb);
	free_direction(map_info);
	ft_error("Check: rgb range\n");
}
