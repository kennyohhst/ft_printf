#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar_fd(char c)
{
	// int i;
	// char	*table;

	// i = 0;
	// table = "abcdef";
	// if (c >= 58 && c <= 63)
	// 	write (1, &(table[c - 58]), 1);
	// else
	// 	write(1, &c, 1);
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


void putnbr(long i, int base)
{
	if (i >= base)
	{
		putnbr(i / base, base);
	}
	ft_putchar_fd((i % base) + '0');
}



int main (void)
{
	int x;
	long y;

	y = (long) &x;
	write(1, "0x", 8);
	// write(1, "x", 2);

	putnbr(y, 16);

	return (0);
}