/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:10:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:07:44 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_format(int *len, va_list params, char format)
{
	if (format == 'c')
		ft_putchar_pf(len, va_arg(params, int));
	else if (format == 's')
		ft_putstr_pf(len, va_arg(params, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr_pf(len, va_arg(params, int));
	else if (format == 'x')
		ft_putnbr_base_pf(len, va_arg(params, unsigned int), BASE_HEX_LOW);
	else if (format == 'X')
		ft_putnbr_base_pf(len, va_arg(params, unsigned int), BASE_HEX_UP);
	else if (format == 'u')
		ft_putnbr_base_pf(len, va_arg(params, unsigned int), BASE_DEC);
	else if (format == 'p')
		ft_putaddress_pf(len, va_arg(params, void *));
	else if (format == '%')
		ft_putchar_pf(len, '%');
}

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		count;

	va_start(params, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr(CONV_CHARS, *(s + 1)) != NULL)
			ft_print_format(&count, params, *(++s));
		else
			ft_putchar_pf(&count, *s);
		s++;
	}
	va_end(params);
	return (count);
}
