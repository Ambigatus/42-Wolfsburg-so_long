/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_address_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:09:37 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/28 15:33:37 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_address_hexa(va_list arg, int *temp)
{
	unsigned long	address;

	address = va_arg(arg, unsigned long);
	if ((void *)address == NULL)
		ft_putstr(PTR_NULL, temp);
	else
	{
		ft_putstr("0x", temp);
		ft_putnbr_uns_l(address, "0123456789abcdef", temp);
	}
}
