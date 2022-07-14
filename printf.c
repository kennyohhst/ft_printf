#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_countdigits(long int x)
{
	int	count;

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

int	types(char **argl, char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == 's')
		return (putstr(*argl));
	if (arg[i] == 'd')
	{
		char *str = ft_itoa(va_arg(&argl, int));
		return (putstr(str));
	}
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
	int i;
	va_list arglist;
	va_start(arglist, (char *) args);

	i = 0;
	int c = 0;
	int len = ft_strlen((char *) args);
	while (args && len != 0)
	{
		if (args[i] == '%')
		{
			args++;
			len--;
			c += types(&arglist, (char *) args);
		}
		if (args[i] == '\n')
			c += write(1, &args[i], sizeof(char));
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
    // // int	x;
	int	y;
	
	y = 	ft_printf("%d", 5);
   	// y =		printf("%s\n%s\n%s\n%d", str, nstr, estr, 5);



    printf("%d", y);
	// printf("banaan\n%s\n", nstr);
    return (0);
}