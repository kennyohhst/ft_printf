/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:04 by kkalika           #+#    #+#             */
/*   Updated: 2022/07/19 16:30:51 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_x(char c)
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
}

int	putnbr_x(unsigned long long i, unsigned int base, int count)
{
	count = 1;
	if (i >= base)
	{
		count += putnbr_x(i / base, base, count);
	}
	ft_putchar_x((i % base) + '0');
	return (count);
}

void	ft_putchar_fd(char c)
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
}

int	putnbr(long long i, int base, int count)
{
	count = 1;
	if (i < 0 && base == 10)
	{
		i = i * -1;
		count += write(1, "-", sizeof(char));
	}
	if (i >= base)
	{
		count += putnbr(i / base, base, count);
	}
	ft_putchar_fd((i % base) + '0');
	return (count);
}

int	putnbr_p(unsigned long long i, unsigned int base, int count)
{
	count = 1;
	if (i >= base)
	{
		count += putnbr_p(i / base, base, count);
	}
	ft_putchar_fd((i % base) + '0');
	return (count);
}
