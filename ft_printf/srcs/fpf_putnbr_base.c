/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:23:48 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 11:48:26 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_pf(int *count, size_t n, const char *base)
{
	unsigned int	base_len;

	base_len = fpf_strlen(base);
	if (base_len == 0)
		return ;
	if (n > (base_len - 1))
		ft_putnbr_base_pf(count, n / base_len, base);
	ft_putchar_pf(count, base[n % base_len]);
}
