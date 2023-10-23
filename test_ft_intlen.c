#include <stdio.h>
#include <math.h>

int	ft_intlen(int num)
{
	int	len;
	int	sign;

	if (num == 0)
		return (1);
	len = 0;
	sign = 0;
	if (num < 0)
	{
		num *= -1;
		sign = 1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len + sign);
}

int	main()
{
	printf("%d, %d, %d\n", ft_intlen(12345), ft_intlen(-123), ft_intlen(0));
	printf("%d\n", (int)pow(10, 4));
	printf("%d\n", 1160225 <<  8 | 7);
	printf("%d\n", 210255 <<  8 | 7);
	printf("%d", 116 * (int)pow(10, 4));
}