#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_putchar_fd(char c)
{
	if (c == 58)
		write(1, "a", sizeof(char));
	else if (c == 59)
		write(1, "b", sizeof(char));
	else if (c == 60)
		write(1, "c", sizeof(char));
	else if (c == 61)
		write(1, "d", sizeof(char));
	else if (c == 62)
		write(1, "e", sizeof(char));
	else if (c == 63)
		write(1, "f", sizeof(char));
	else
		write(1, &c, 1);
	return (0);
}

int putnbr(long long i, int base, int count)
{
	count = 1;

	if (i < 0)
	{
		i = i * -1;
		count += write(1, "-", sizeof(char));
	}
	if (i >= base)
	{
		count += putnbr(i / base, base, count);
	}
	count += ft_putchar_fd((i % base) + '0');
	return (count);
}

int main (void)
{
	long i;
	int c;

	i = -11000;
	c = putnbr(i, 10, 0);
	printf("\n");
	putnbr(c, 10, 0);
	return (0);
}