#include "../cub3D.h"

void	check_valid_map_path(char *argv)
{
	int	fd;

	if (rev_strncmp(argv, "buc.", 4) == -1)
		ft_error("Check: invalid map extension\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid map path\n");
	close(fd);
}


void	check_valid_texture_form(int type, char **info)
{
	int	i;

	i = 0;
	if (type == -1)
		ft_error("Check : invalidate file form\n");
	if (type >= EA_PATH && type <= CEILING)
	{
		while (info[i] != NULL)
		{
			i++;
		}
		if (i != 2)
			ft_error("Check : invalidate file form\n");
	}

}

void	check_valid_rgb_form(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != NULL)
	{
		i++;
	}
	if (i != 3)
		ft_error("Check : invalidate file form\n");
}

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

void	check_valid_rgb_value(t_map *info_map)
{
	if (info_map->floor->r < 0 || info_map->floor->r > 255 \
	|| info_map->floor->g < 0 || info_map->floor->g > 255 \
	|| info_map->floor->b < 0 || info_map->floor->b > 255)
		ft_error("Check: invalid color range");
	if (info_map->ceiling->r < 0 || info_map->ceiling->r > 255 \
	|| info_map->ceiling->g < 0 || info_map->ceiling->g > 255 \
	|| info_map->ceiling->b < 0 || info_map->ceiling->b > 255)
		ft_error("Check: invalid color range");
}
