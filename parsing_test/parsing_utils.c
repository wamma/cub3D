#include "test.h"


void	check_valid_rgb(char **rgb)
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

void	check_valid_texture_info(int type, char **info)
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
	}
	if (i != 2)
		ft_error("Check : invalidate file form\n");
}

int	get_element_type(char **info)
{
	int	type;

	type = -1;
	if (info[0] == NULL)
		type = 0;
	if (ft_strncmp(info[0], "EA", ft_strlen(info[0]) == 0))
		type = EA_PATH;
	if (ft_strncmp(info[0], "WE", ft_strlen(info[0]) == 0))
		type = WE_PATH;
	if (ft_strncmp(info[0], "SO", ft_strlen(info[0]) == 0))
		type = SO_PATH;
	if (ft_strncmp(info[0], "NO", ft_strlen(info[0]) == 0))
		type = NO_PATH;
	if (ft_strncmp(info[0], "F", ft_strlen(info[0]) == 0))
		type = FLOOR;
	if (ft_strncmp(info[0], "C", ft_strlen(info[0]) == 0))
		type = CEILING;
	check_valid_texture_info(type, info);
	return (type);
}