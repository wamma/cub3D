#include "test.h"

void	free_direction(t_map *map)
{
	free(map->no_path);
	free(map->so_path);
	free(map->ea_path);
	free(map->we_path);
}
