/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:16:26 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/24 13:30:23 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_str(va_list arg, int *temp)
{
	char	*str;

	str = va_arg(arg, void *);
	if (str == NULL)
		ft_putstr("(null)", temp);
	else
		ft_putstr(str, temp);
}
