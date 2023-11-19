#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const	char *s, ...);

int	main()
{
	int	i = printf("%d\n", 11);
	printf("%d\n", i);
	int s = ft_printf("%d\n", 11);
	printf("%d\n", s);
}

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
		//len = ft_pointer(arg);
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