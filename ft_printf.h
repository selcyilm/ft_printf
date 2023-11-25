/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/19 12:59:10 by selcyilm      #+#    #+#                 */
/*   Updated: 2023/11/25 14:05:04 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const	char *format, ...);
int		match_arg(va_list arg, const char c);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_putpos(unsigned long int nb, const char c);
int		ft_hex(va_list arg, const char c);
int		ft_putnbr(int nb);
int		ft_putptr(va_list arg);
int		ft_put_u(unsigned int nb);

#endif