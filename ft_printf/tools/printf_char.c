/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:32:16 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/24 12:37:10 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_char(va_list arg, int *temp)
{
	char	c;

	c = va_arg(arg, int);
	*temp += write(1, &c, 1);
}
