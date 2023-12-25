/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/25 13:03:32 by selcyilm      #+#    #+#                 */
/*   Updated: 2023/12/25 11:55:26 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putptr(va_list arg)
{
	unsigned long int	p;

	p = va_arg(arg, unsigned long int);
	if (!p || p == 0)
		return (ft_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_putpos(p, 'p'));
}

/*int main(int ac, char **av)
{
	int i = atoi(av[1]);
	int *p = &i;
	ft_printf("Mine: %p\n", p);
	printf("Orig: %p\n", p);
}*/