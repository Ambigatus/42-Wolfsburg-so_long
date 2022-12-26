/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:22:10 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/28 16:07:24 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_check(const char *str, va_list arg, int count, int *temp)
{
	if (str[count] == 'c')
		printf_char(arg, temp);
	if (str[count] == '%')
		*temp += write(1, "\%", 1);
	if (str[count] == 'i' || str[count] == 'd')
		printf_int(arg, temp);
	if (str[count] == 'u')
		printf_uint(arg, temp);
	if (str[count] == 'x' || str[count] == 'X')
		printf_hexa(arg, str[count], temp);
	if (str[count] == 'p')
		printf_address_hexa(arg, temp);
	if (str[count] == 's')
		printf_str(arg, temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int		*temp;
	int		i;

	va_start(args, format);
	result = 0;
	i = 0;
	temp = &result;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			format_check(format, args, i, temp);
		}
		else
			result += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}
