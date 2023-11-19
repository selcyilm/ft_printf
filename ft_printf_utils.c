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
	int	i;
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
	int	a;
	int	len;
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
