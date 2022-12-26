/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:26:43 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/24 13:37:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_u(unsigned int n, int	*nbr_temp)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, nbr_temp);
		n %= 10;
	}
	ft_putchar(n + '0', nbr_temp);
}
