/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:50:57 by kkalika           #+#    #+#             */
/*   Updated: 2022/07/19 15:02:02 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *args, ...);
int	ft_putchar_x(char c);
int	putnbr_x(unsigned long long i, unsigned int base, int count);
int	ft_putchar_fd(char c);
int	putnbr(long long i, int base, int count);
int	putnbr_p(unsigned long long i, unsigned int base, int count);

#endif