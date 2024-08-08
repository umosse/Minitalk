/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:06:04 by umosse            #+#    #+#             */
/*   Updated: 2023/11/30 16:15:23 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;

	va_list(args);
	i = 0;
	len = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_mandatory(&s[i++], args);
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	ft_mandatory(const char *fmt, va_list args)
{
	int	len;

	len = 0;
	if (*fmt == 's')
		len += ft_is_s(va_arg(args, char *));
	else if (*fmt == 'c')
		len += ft_is_c((char)va_arg(args, int));
	else if (*fmt == 'd' || *fmt == 'i')
		len += ft_is_di(va_arg(args, int));
	else if (*fmt == 'u')
		len += ft_is_u(va_arg(args, unsigned int));
	else if (*fmt == 'p')
		len += ft_is_p(va_arg(args, void *));
	else if (*fmt == 'x')
		len += ft_is_xlow(va_arg(args, unsigned int));
	else if (*fmt == 'X')
		len += ft_is_xup(va_arg(args, unsigned int));
	else if (*fmt == '%')
		len += ft_putchar('%');
	return (len);
}
