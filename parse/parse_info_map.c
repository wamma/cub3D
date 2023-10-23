#include "../cub3D.h"

int	ft_intlen(int num)
{
	int	len;
	int	sign;

	if (num == 0)
		return (1);
	len = 0;
	sign = 0;
	if (num < 0)
	{
		num *= -1;
		sign = 1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len + sign);
}

int	rgb_to_int(t_rgb *rgb)
{
	int	sum_of_length;
	int	r;
	int	g;
	int	b;
	int	result;

	sum_of_length = ft_intlen(rgb->r) + ft_intlen(rgb->g) + ft_intlen(rgb->b);

	r = rgb->r * ((int)pow(10, (ft_intlen(rgb->g) + ft_intlen(rgb->b))));
	g = rgb->g * ((int)pow(10, ft_intlen(rgb->b)));
	b = rgb->b;
	//result = r + g + b;
	result = (r + g + b) << 8 | sum_of_length;
	return (result);
}

void	get_rgb_to_int(t_map *info_map)
{
	int	color_scale= 1.0f/255;
	//info_map->floor_int_rgb = rgb_to_int(info_map->floor);
	//info_map->ceiling_int_rgb = rgb_to_int(info_map->ceiling);
	info_map->floor_int_rgb = (color_scale * info_map->floor->r << 16) + (color_scale * info_map->floor->g << 8) + (color_scale * info_map->floor->g);
	info_map->ceiling_int_rgb = (color_scale * info_map->ceiling->r << 16) + (color_scale * info_map->ceiling->g << 8) + (color_scale * info_map->ceiling->g);
	printf("floor: %d\n", info_map->floor_int_rgb);
}

//color_scale = 1.0f/255
////color = (color_scale * pixel[2] << 16) + (color_scale * pixel[1]; << 8)
////        + (color_scale * pixel[0]);
void	parse_info_map(t_map *info_map, char *map_path)
{
	check_valid_map_path(map_path);
	info_map->map_path = map_path;
	get_texture_info(info_map);
	get_rgb_to_int(info_map);
	check_valid_texture_path(info_map);
	check_duplicated_map_path(info_map);
	info_map->map = parse_map(info_map);
}
