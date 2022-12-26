/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:02:25 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/28 16:25:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_hexa(va_list arg, char c, int *temp)
{
	unsigned long	num;

	num = va_arg(arg, unsigned long);
	if (c == 'X')
		ft_putnbr_uns(num, "0123456789ABCDEF", temp);
	if (c == 'x')
		ft_putnbr_uns(num, "0123456789abcdef", temp);
}
