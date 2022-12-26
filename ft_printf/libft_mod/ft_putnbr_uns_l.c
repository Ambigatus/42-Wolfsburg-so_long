/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:16:43 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/28 16:22:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_uns_l(unsigned long n, char *base, int *nbr_temp)
{
	unsigned long	base_len;

	base_len = 0;
	if (check_base(base))
	{
		while (base[base_len])
			base_len++;
		if (n > base_len - 1)
		{
			ft_putnbr_uns_l(n / base_len, base, nbr_temp);
			n %= base_len;
		}
		ft_putchar(base[n], nbr_temp);
	}
}
