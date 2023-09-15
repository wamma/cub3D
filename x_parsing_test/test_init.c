#include "test.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}


void	init_floor_and_ceiling_structure(t_map *info_map)
{
	ft_memset(info_map, 0, sizeof(t_map));
	info_map->floor = malloc(sizeof(t_rgb));
	//if (!info_map->floor)
	//	ft_error("Failed malloc\n");
	ft_memset(info_map->floor, 0, sizeof(t_rgb));
	info_map->ceiling = malloc(sizeof(t_rgb));
	//if (!info_map->ceiling)
	//	ft_error("Failed malloc\n");
	ft_memset(info_map->ceiling, 0, sizeof(t_rgb));	
}

void	init_t_map(char *map_path, t_map *info_map)
{
	init_floor_and_ceiling_structure(info_map);
	info_map->map_path = map_path;
}

int main()
{
	t_map map;

	init_t_map("path", &map);
	printf("here: %d\n", map.floor->r);
	printf("%p\n", map.floor);
}

//gcc init.c