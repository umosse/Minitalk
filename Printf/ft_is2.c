/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:14:01 by umosse            #+#    #+#             */
/*   Updated: 2023/11/30 16:16:10 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_p(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_putnbr_ptr((unsigned long)ptr, "0123456789abcdef");
	return (len);
}

int	ft_is_xlow(unsigned int i)
{
	int	len;

	len = 0;
	len += ft_putnbr_base(i, "0123456789abcdef");
	return (len);
}

int	ft_is_xup(unsigned int i)
{
	int	len;

	len = 0;
	len += ft_putnbr_base(i, "0123456789ABCDEF");
	return (len);
}
