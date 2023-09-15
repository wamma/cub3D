#include "../cub3D.h"

int	is_all_white_space(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (1);
	else
		return (0);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
