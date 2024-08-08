/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:59:10 by umosse            #+#    #+#             */
/*   Updated: 2024/01/26 16:20:45 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_mandatory(const char *fmt, va_list args);
int	ft_is_s(char *s);
int	ft_is_c(char s);
int	ft_is_di(int i);
int	ft_is_u(unsigned int i);
int	ft_is_p(void *ptr);
int	ft_is_xlow(unsigned int i);
int	ft_is_xup(unsigned int i);
int	printf_strlen(const char *str);
int	ft_putchar(char c);
int	ft_putnbr(long int n);
int	ft_putstr(char *s);
int	ft_putnbr_base(long int n, char *base);
int	ft_putnbr_ptr(unsigned long int n, char *base);

#endif