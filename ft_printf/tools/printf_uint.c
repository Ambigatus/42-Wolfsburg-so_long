/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:39:59 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/24 12:37:24 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_uint(va_list arg, int *temp)
{
	unsigned int	num;

	num = va_arg(arg, unsigned int);
	ft_putnbr_u(num, temp);
}
