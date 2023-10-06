#include <stdio.h>

int main()
{
	int x = -1;
	while (++x < 10)
	{
		printf("%d\n", x);
	}
	printf("%d\n", x);
}