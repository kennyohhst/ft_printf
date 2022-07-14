#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

size_t	ft_countdigits(long int x)
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
	while (str[i])
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int c)
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

int	types(va_list argl, char *arg)
{
	int	i;
	char	sc;

	i = 0;
	if (arg[i] == 's')
		return (putstr(va_arg(argl, char *)));
	if (arg[i] == 'd' || arg[i] == 'i')
		return (putstr(ft_itoa(va_arg(argl, int))));
	if (arg[i] == 'c')
	{
		sc = va_arg(argl, int);
		return (write(1, &sc, sizeof(char)));
	}
	if (arg[i] == '%')
		return (write(1, &arg[0], sizeof(char)));
	if	(arg[i] == 'u')
		return (putstr(ft_utoa(va_arg(argl, unsigned int))));
	else
		write(1, &argl[i], sizeof(char));
	
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_printf(const char *args, ...)
{
	va_list arglist;
	va_start(arglist, (char *) args);
	int	c;

	c = 0;
	int len = ft_strlen((char *) args);
	while (args && len != 0)
	{
		if (args[0] != '%' && ft_strlen((char *) args) != 0)
		{	
			c += write(1, &args[0], sizeof(char));
			args++;
			len--;
		}
		if (args[0] == '%')
		{
			args++;
			len--;
			c += types(arglist, (char *) args);
			args++;
			len--;
		}
	}
	va_end(arglist);
	return (c);
}

int main(void)
{
	// const char str[] = "banana";
	const char nstr[] = "second";
	// const char estr[] = "turd";
    int	x;
	// int	y;
	
	x = 	ft_printf("MINE\npercentage:%%\nchar:%c\nchar*:%s\nunsignedint:%u\nsignedintD:%d\ndecimalI:%i\n\n\n", 'c', nstr, 4294967295, -2147483647, -2147483646);
	// y = 	printf("NOTS\npercentage:%%\nchar:%c\nchar*:%s\nunsignedint:%ld\nsignedintD:%d\ndecimalI:%i\n\n\n", 'c', nstr, 4294967295, -2147483647, -2147483646);

	


	// system("leaks a.out");
    printf("\nlength: %d\n", x);
    return (0);
}