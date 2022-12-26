/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:51:54 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/24 13:33:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(int n, int *nbr_temp)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		ft_putchar('-', nbr_temp);
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnbr(num / 10, nbr_temp);
		num %= 10;
	}
	ft_putchar(num + '0', nbr_temp);
}
