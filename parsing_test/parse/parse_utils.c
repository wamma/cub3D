#include "test.h"

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