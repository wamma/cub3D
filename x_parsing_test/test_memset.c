#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

int main()
{
	int arr[6];

	for(int i = 0; i < 6; i++)
	{
		arr[i] = 7;
	}
	//ft_memset(arr, 5, 6 * sizeof(int));
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
}