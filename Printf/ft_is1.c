/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:08:05 by umosse            #+#    #+#             */
/*   Updated: 2023/11/30 16:16:02 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_s(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len += ft_putstr(s);
	return (len);
}

int	ft_is_c(char s)
{
	int	len;

	len = 0;
	len += ft_putchar(s);
	return (len);
}

int	ft_is_di(int i)
{
	int	len;

	len = 0;
	len += ft_putnbr(i);
	return (len);
}

int	ft_is_u(unsigned int i)
{
	int	len;

	len = 0;
	len += ft_putnbr(i);
	return (len);
}
