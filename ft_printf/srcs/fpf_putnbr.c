/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:38:45 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:07:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_pf(int *count, int n)
{
	if (n == -2147483648)
	{
		ft_putstr_pf(count, "-2147483648");
		return ;
	}
	else if (n < 0)
		ft_putchar_pf(count, '-');
	ft_putnbr_base_pf(count, n, BASE_DEC);
}
