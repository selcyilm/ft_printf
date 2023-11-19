/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/19 15:35:17 by selcyilm      #+#    #+#                 */
/*   Updated: 2023/11/19 15:37:31 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_hex(va_list arg, const char *hex)
{
	int	len;

	len = 0;
	len = ft_putpos((unsigned int)va_arg(arg, int), hex);
	if (len == 0)
		len = ft_putchar('0');
	return (len);
}

int	ft_putpos(unsigned int nb, const char *hex)
{
	int			a;
	int			len;
	long long	tmp;

	tmp = (long long)nb;
	if (tmp < 0)
	{
		write(1, "-", 1);
		len = 1;
		tmp *= -1;
	}
	if (tmp != 0)
	{
		a = nb % ft_strlen(hex);
		len += ft_putpos(tmp / ft_strlen(hex), hex) + 1;
		write(1, &hex[a], 1);
		return (len);
	}
	else
		return (0);
}
