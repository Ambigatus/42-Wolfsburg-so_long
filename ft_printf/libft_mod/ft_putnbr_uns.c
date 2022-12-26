/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:46:56 by ddzuba            #+#    #+#             */
/*   Updated: 2022/07/04 15:08:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_uns(unsigned int n, char *base, int *nbr_temp)
{
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n > base_len - 1)
	{
		ft_putnbr_uns_l(n / base_len, base, nbr_temp);
		n %= base_len;
	}
	ft_putchar(base[n], nbr_temp);
}
