#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


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
	int i;

	i = 0;
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
	return (i);
}

int putnbr_x(long i, int base)
{
	int	count;
	count = 1;
	if (i >= base)
	{
		count = 1 + putnbr_x(i / base, base);
	}
	ft_putchar_x((i % base) + '0');
	return (count);
}

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
	int i;

	i = 0;
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
	return (i);
}


int putnbr(long i, int base)
{
	int	count;
	count = 1;
	if (i >= base)
	{
		count = 1 + putnbr(i / base, base);
	}
	ft_putchar_fd((i % base) + '0');
	return (count);
}


int	types(va_list *argl, char *arg)
{
	int	i;
	char	sc;

	i = 0;
	if (arg[i] == 's')
		return (putstr(va_arg(*argl, char *)));
	if (arg[i] == 'd' || arg[i] == 'i')
		return (putstr(ft_itoa(va_arg(*argl, int))));
	if (arg[i] == 'c')
	{
		sc = va_arg(*argl, int);
		return (write(1, &sc, sizeof(char)));
	}
	if (arg[i] == '%')
		return (write(1, &arg[0], sizeof(char)));
	if	(arg[i] == 'u')
		return (putstr(ft_utoa(va_arg(*argl, unsigned int))));
	if (arg[i] == 'p')
	{
		putstr("0x");
		return (putnbr(va_arg(*argl, long), 16) + 2);
	}
	if (arg[i] == 'x')
		return (putnbr(va_arg(*argl, long), 16));
	if (arg[i] == 'X')
		return (putnbr_x(va_arg(*argl, long), 16));
	// else
	// 	write(1, &argl[i], sizeof(char));
	return (0);
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
		if (len == 0)
			break;
		args++;
		len--;
	}
	va_end(arglist);
	return (c);
}

int main(void)
{
	// const char str[] = "banana";
	// const char nstr[] = "second";
	// const char estr[] = "turd";
    int	x;
	// int	y;
	int	z;

	// x = ft_printf("MINE\nstring: %s\nchar: %c\nint D: %d\nint I: %i\npercentage: %%%%\nunsigned int: %u\npointer adress: %p\nunsigned hex L: %x\nunsigned hex U: %X\n", str, 97, 2147483647, -2147483648, 4294967295, &z, 4294967295,  4294967295);
	// z = printf("blob\nstring: %s\nchar: %c\nint D: %d\nint I: %li\npercentage: %%%%\nunsigned int: %ld\npointer adress: %p\nunsigned hex L: %lx\nunsigned hex U: %lX\n", str, 97, 2147483647, -2147483648, 4294967295, &z, 4294967295,  4294967295);

	// x = 	ft_printf("MINE\npercentage : %%\nchar : %c\nchar* : %s\nunsigned int : %u\nsigned int D : %d\ndecimal I : %i\n\n\n", 'c', nstr, 4294967295, -2147483647, -2147483646);
	// x = 	printf("MINE\naddress: %p\npercentage:%%\nchar:%c\nchar*:%s\nunsignedint:%ld\nsignedintD:%d\ndecimalI:%i\n\n\n", &x, 'c', nstr, 4294967295, -2147483647, -2147483646);
	
	
	x = ft_printf(" %c %c %c ", '1', '2', '3');
	z = printf(" %c %c %c ", '1', '2', '3');

	


	// system("leaks a.out");
    printf("\nlength MINE: %d\nlength blob: %d\n", x, z);
    return (0);
}





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