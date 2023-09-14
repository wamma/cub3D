#include "test.h"

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




int	get_element_type(char **info)
{
	int	type;

	type = -1;
	if (info[0] == NULL)
		type = 0;
	else if (is_same(info[0], "EA") == 1)
		type = EA_PATH;
	else if (is_same(info[0], "WE") == 1)
		type = WE_PATH;
	else if (is_same(info[0], "SO") == 1)
		type = SO_PATH;
	else if (is_same(info[0], "NO") == 1)
		type = NO_PATH;
	else if (is_same(info[0], "F") == 1)
		type = FLOOR;
	else if (is_same(info[0], "C") == 1)
		type = CEILING;
	check_valid_texture_form(type, info);
	return (type);
}
