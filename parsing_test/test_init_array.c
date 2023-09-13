#include <stdlib.h>
#include <stdio.h>

int	*init_array(int size)
{
	int i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = 72;
		i++;
	}
	return (arr);
}

int main()
{
	int *arr = init_array(6);
	for(int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
}