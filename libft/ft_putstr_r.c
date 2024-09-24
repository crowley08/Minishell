/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:47:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 11:17:16 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_r(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}
