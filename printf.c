#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_x(char c)
{
	if (c == 58)
		write(1, "A", sizeof(char));
	else if (c == 59)
		write(1, "B", sizeof(char));
	else if (c == 60)
		write(1, "C", sizeof(char));
	else if (c == 61)
		write(1, "D", sizeof(char));
	else if (c == 62)
		write(1, "E", sizeof(char));
	else if (c == 63)
		write(1, "F", sizeof(char));
	else
		write(1, &c, 1);
	return (0);
}

size_t	ft_countdigits(long long x)
{
	size_t	count;

	if (x > 0)
		count = 0;
	if (x <= 0)
		count = 1;
	while (x != 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int c)
{
	long int	tempnb;
	int			x;
	char		*number;

	tempnb = (long) c;
	x = ft_countdigits(tempnb) - 1;
	number = (char *) malloc(ft_countdigits(tempnb) + 1);
	if (!number)
		return (NULL);
	number[ft_countdigits(c)] = '\0';
	if (tempnb < 0)
	{
		number[0] = '-';
		tempnb = tempnb * -1;
	}
	if (tempnb == 0)
		number[x] = '0';
	while (tempnb != 0 && x >= 0)
	{
		number[x] = (char)(tempnb % 10) + '0';
		tempnb = tempnb / 10;
		x--;
	}
	return (number);
}

int putstr(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
	return (i);
}

char	*ft_utoa(long c)
{
	long int	tempnb;
	int			x;
	char		*number;

	tempnb = (long) c;
	x = ft_countdigits(tempnb) - 1;
	number = (char *) malloc(ft_countdigits(tempnb) + 1);
	if (!number)
		return (NULL);
	number[ft_countdigits(c)] = '\0';
	if (tempnb < 0)
	{
		number[0] = '-';
		tempnb = tempnb * -1;
	}
	if (tempnb == 0)
		number[x] = '0';
	while (tempnb != 0 && x >= 0)
	{
		number[x] = (char)(tempnb % 10) + '0';
		tempnb = tempnb / 10;
		x--;
	}
	return (number);
}

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

int putnbr_x(long long i, int base, int count)
{
	count = 1;

	if (i < 0)
	{
		i = i * -1;
		count += write(1, "-", sizeof(char));
	}
	if (i >= base)
	{
		count += putnbr_x(i / base, base, count);
	}
	count += ft_putchar_x((i % base) + '0');
	return (count);
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


// int putnbr(long long i, long long base, int count)
// {
// 	if (i < 0)
// 	{
// 		i = i * -1;
// 		count += write(1, "-", sizeof(char));
// 	}
// 	if (i >= base)
// 	{
// 		putnbr(i / base, base, count);
// 	}
// 	count = ft_putchar_fd((i % base) + '0');
// 	return (count);
// }


int	types(va_list *argl, char *arg)
{
	char	sc;

	if (arg[0] == 's')
		return (putstr(va_arg(*argl, char *)));
	if (arg[0] == 'd' || arg[0] == 'i')
		return (putnbr(va_arg(*argl, int), 10, 0));
	if (arg[0] == 'c')
	{
		sc = va_arg(*argl, int);
		return (write(1, &sc, sizeof(char)));
	}
	if (arg[0] == '%')
		return (write(1, &arg[0], sizeof(char)));
	if	(arg[0] == 'u')
		return (putnbr(va_arg(*argl, unsigned int), 10, 0));
	// if (arg[0] == 'p')
	// {
	// 	putstr("0x");
	// 	return (putnbr(va_arg(*argl, long), 16) - 1);
	// }
	if (arg[0] == 'x')
		return (putnbr(va_arg(*argl, unsigned int), 16, 0));
	if (arg[0] == 'X')
		return (putnbr_x(va_arg(*argl, unsigned int), 16, 0));
	return (0);
}

int ft_printf(const char *args, ...)
{
	va_list arglist;
	va_start(arglist, (char *) args);
	int	c;

	c = 0;
	int len = ft_strlen((char *) args);
	while (*args)
	{
		while (args[0] != '%' && ft_strlen((char *) args) != 0)
		{	
			c += write(1, &args[0], sizeof(char));
			args++;
			len--;
		}
		if (args[0] == '%')
		{
			c += types(&arglist, (char *) args + 1);
			args++;
			len--;
		}
		if (ft_strlen((char *) args) == 0)
			break;
		args++;
		len--;
	}
	va_end(arglist);
	return (c);
}

// int main(void)
// {

//     int	x;
// 	int	y;
// 	// long	z = -1;
	
// 	x = ft_printf("%d", 111);

// 	y = printf("%d", 111);

// 	// 	printf(" %p ", -1));
// 	// printf(" %p ", 1));
// 	// printf(" %p ", 15));
// 	// printf(" %p ", 16));
// 	// printf(" %p ", 17));
// 	// printf(" %p %p ", LONG_MIN, LONG_MAX));
// 	// printf(" %p %p ", INT_MIN, INT_MAX));
// 	// printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 	// printf(" %p %p ", 0, 0));


// 	// system("leaks a.out");
//     printf("\nlength MINE: %d\nlength blob: %d\n", x, y);
//     return (0);
// }





// void	ft_putnbr_fd(long n)
// {
// 	if ((long) n == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n = n * -1;
// 	}
// 	if (n >= 10)
// 		ft_putnbr_fd(n / 10);
// 	ft_putchar_fd((n % 10) + '0', 1);
// }
