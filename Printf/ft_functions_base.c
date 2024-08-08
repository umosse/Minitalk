/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:30 by umosse            #+#    #+#             */
/*   Updated: 2024/01/26 16:21:12 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long int n, char *base)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= printf_strlen(base))
	{
		len += ft_putnbr_base(n / printf_strlen(base), base);
		len += ft_putnbr_base(n % printf_strlen(base), base);
	}
	else
	{
		len += ft_putchar(base[n]);
	}
	return (len);
}

int	ft_putnbr_ptr(unsigned long int n, char *base)
{
	int	len;

	len = 0;
	if (n >= (unsigned long int)printf_strlen(base))
	{
		len += ft_putnbr_ptr(n / printf_strlen(base), base);
		len += ft_putnbr_ptr(n % printf_strlen(base), base);
	}
	else
	{
		len += ft_putchar(base[n]);
	}
	return (len);
}
