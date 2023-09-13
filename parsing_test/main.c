#include "test.h"

void	check_valid_texture_path(t_map *info_map)
{
	int	fd;

	fd = open(info_map->no_path, O_RDONLY);
	if (fd < 0)
	{
		/*free_info_map(info_map, "Check: invalid texture path\n");나중에 이렇게 free랑 합치기*/
		ft_error("Check: invalid texture path\n");
	}
	close(fd);
	fd = open(info_map->so_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
	fd = open(info_map->we_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
	fd = open(info_map->ea_path, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid texture path\n");
	close(fd);
}

void	fill_info_map(t_map *info_map, char *map_path)
{
	check_valid_path(map_path);
	info_map->map_path = map_path;
	get_texture_info(info_map);
	check_valid_texture_path(info_map);
	//check_valid_rgb_value(info_map);
}

int main(int argc, char **argv)
{
	t_map	info_map;

	if (argc != 2)
		ft_error("Check: num of argv\n");
	init_s_map(&info_map);
	fill_info_map(&info_map, argv[1]);

}