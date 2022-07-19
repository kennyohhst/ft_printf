/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:50:57 by kkalika           #+#    #+#             */
/*   Updated: 2022/07/19 18:58:40 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *args, ...);
void	ft_putchar_x(char c);
int		ft_putnbr_x(unsigned long long i, unsigned int base, int count);
void	ft_putchar(char c);
int		ft_putnbr(long long i, int base, int count);
int		ft_putnbr_p(unsigned long long i, unsigned int base, int count);
int		ft_putstr(char *str);
int		ft_types(va_list *argl, char *arg);
int		ft_strlen(char *str);

#endif