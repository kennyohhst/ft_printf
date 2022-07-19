/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:57:00 by kkalika           #+#    #+#             */
/*   Updated: 2022/07/19 19:03:08 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_types(va_list *argl, char *arg)
{
	char	sc;

	if (arg[0] == 's')
		return (ft_putstr(va_arg(*argl, char *)));
	if (arg[0] == 'd' || arg[0] == 'i')
		return (ft_putnbr(va_arg(*argl, int), 10, 0));
	if (arg[0] == 'c')
	{
		sc = va_arg(*argl, int);
		return (write(1, &sc, sizeof(char)));
	}
	if (arg[0] == '%')
		return (write(1, &arg[0], sizeof(char)));
	if (arg[0] == 'u')
		return (ft_putnbr(va_arg(*argl, unsigned int), 10, 0));
	if (arg[0] == 'p')
		return (ft_putstr("0x") + ft_putnbr_p(va_arg(*argl, long long), 16, 0));
	if (arg[0] == 'x')
		return (ft_putnbr(va_arg(*argl, unsigned int), 16, 0));
	if (arg[0] == 'X')
		return (ft_putnbr_x(va_arg(*argl, unsigned int), 16, 0));
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
		if (args[0] == '%' && ft_strlen((char *) args) != 0)
		{
			c += ft_types(&arglist, (char *) args + 1);
			args++;
		}
		if (ft_strlen((char *) args) == 0)
			break ;
		args++;
	}
	va_end(arglist);
	return (c);
}
