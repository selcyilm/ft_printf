/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/19 12:59:10 by selcyilm      #+#    #+#                 */
/*   Updated: 2023/11/19 14:57:44 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const	char *format, ...);
int	match_arg(va_list arg, const char c);
size_t	ft_strlen(const char *str);
int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putpos(unsigned int nb, const char *hex);
int	ft_hex(va_list arg, const char *hex);
int	ft_putnbr(int nb);

#endif