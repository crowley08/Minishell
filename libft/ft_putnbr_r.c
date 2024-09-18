/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:56:05 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 10:52:57 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_r(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_r("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar_r('-');
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr_r(n / 10);
	n = (n % 10) + 48;
	count += ft_putchar_r(n);
	return (count);
}
