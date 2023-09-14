#include "../cub3D.h"

void	free_ppc(char **ppc)
{
	int	i;

	i = 0;
	while (ppc[i] != NULL)
	{
		free(ppc[i]);
		ppc[i] = NULL;
		i++;
	}
	free(ppc);
	ppc = NULL;
}