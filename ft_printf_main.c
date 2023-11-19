/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/19 15:35:15 by selcyilm      #+#    #+#                 */
/*   Updated: 2023/11/19 15:37:05 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const	char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += match_arg(arg, s[i]);
		}
		else
		{
			write(1, &s[i], 1);
			if (s[i])
				len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int	match_arg(va_list arg, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		len = 1;
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		len = ft_hex(arg, "0123456789");
	if (c == 'x')
		len = ft_hex(arg, "0123456789abcdef");
	if (c == 'X')
		len = ft_hex(arg, "0123456789ABCDEF");
	if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_putnbr(int nb)
{
	int	i;
	int	n;

	i = 0;
	if (i == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
	}
	n = nb % 10 + 48;
	i += write(1, &n, 1);
	return (i);
}
