/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:57:00 by kkalika           #+#    #+#             */
/*   Updated: 2022/07/19 15:00:26 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	putstr(char *str)
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
	if (arg[0] == 'u')
		return (putnbr(va_arg(*argl, unsigned int), 10, 0));
	if (arg[0] == 'p')
	{
		putstr("0x");
		return (putnbr_p(va_arg(*argl, long long), 16, 0) + 2);
	}
	if (arg[0] == 'x')
		return (putnbr(va_arg(*argl, unsigned int), 16, 0));
	if (arg[0] == 'X')
		return (putnbr_x(va_arg(*argl, unsigned int), 16, 0));
	return (0);
}

int	ft_printf(const char *args, ...)
{
	va_list	arglist;
	int		c;

	va_start(arglist, (char *) args);
	c = 0;
	while (*args)
	{
		while (args[0] != '%' && ft_strlen((char *) args) != 0)
		{	
			c += write(1, &args[0], sizeof(char));
			args++;
		}
		if (args[0] == '%')
		{
			c += types(&arglist, (char *) args + 1);
			args++;
		}
		if (ft_strlen((char *) args) == 0)
			break ;
		args++;
	}
	va_end(arglist);
	return (c);
}

// int main(void)
// {

//     long	x;
// 	// int	y;
// 	long z;

// 	z = LONG_MIN;
// 	x = LONG_MAX;
// 	// y = printf("%p\n", (void *) -1);
// 	// y = printf("%p", &z);

// 	// int test = -1;
// 	// y = ft_printf("This %p is even stranger", (void *)-1);
// 	// x = ft_printf("TEST->%p\n", &test);

// 	ft_printf(" %p %p ", (void *)-1, &x);

// 	printf(" %p %p ", (void *)-1, &x);

// 	// system("leaks a.out");
//     // printf("\nlength MINE: %d\nlength blob: %d\n", x, y);
//     return (0);
// }
