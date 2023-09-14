#include "../cub3D.h"

int	rev_strncmp(char *s1, char *s2, int n)
{
	int	l;
	int	i;

	l = ft_strlen(s1);
	i = 0;
	if (n == 0)
		return (0);
	if (n > l)
		return (-1);
	while ((n > 0))
	{
		if (s1[l - 1] != s2[i])
		{
			return (-1);
		}
		i++;
		l--;
		n--;
	}
	return (1);
}

int	is_same(char *s1, char *s2)
{
	int i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

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