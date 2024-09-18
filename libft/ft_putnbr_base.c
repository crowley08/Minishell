/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:56:05 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 11:16:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(size_t n, const char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (base_len == 0)
		return ;
	if (n > (base_len - 1))
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
}
