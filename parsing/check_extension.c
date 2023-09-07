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

void	check_extension(char *argv)
{
	if (rev_strncmp(argv, "buc.", 4) == -1)
		ft_error("Check: map extension");
}
