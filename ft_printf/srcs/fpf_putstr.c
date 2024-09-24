/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:47:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:07:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_pf(int *count, const char *s)
{
	if (!s)
		ft_putstr_pf(count, "(null)");
	else
		while (*s)
			ft_putchar_pf(count, *(s++));
}
