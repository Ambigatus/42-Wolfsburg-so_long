/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:18:57 by ddzuba            #+#    #+#             */
/*   Updated: 2022/06/28 17:33:10 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# elif __linux__
#  define PTR_NULL "(nil)"
# endif

//libft_mod files

void	ft_putchar(char c, int *nbr_temp);
void	ft_putnbr(int n, int *nbr_temp);
void	ft_putstr(char *s, int *nbr_temp);
void	ft_putnbr_uns(unsigned int n, char *base, int *nbr_temp);
void	ft_putnbr_uns_l(unsigned long n, char *base, int *nbr_temp);
void	ft_putnbr_u(unsigned int n, int	*nbr_temp);

//Tools files

void	printf_char(va_list arg, int *temp);
void	printf_int(va_list arg, int *temp);
void	printf_uint(va_list arg, int *temp);
void	printf_address_hexa(va_list arg, int *temp);
void	printf_hexa(va_list arg, char c, int *temp);
void	printf_str(va_list arg, int *temp);

//Also printf
int		ft_printf(const char *format, ...);

#endif