/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:01:34 by umosse            #+#    #+#             */
/*   Updated: 2024/01/26 16:22:03 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
	{
		len += ft_putchar(n + 48);
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
