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
