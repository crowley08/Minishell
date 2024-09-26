/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:59:44 by saandria          #+#    #+#             */
/*   Updated: 2024/09/26 11:01:50 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if ((nptr[i] == '-') && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
			sign *= -1;
		else if ((nptr[i] == '+') && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
			sign *= 1;
		else
			return (res);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i++;
	}
	return (sign * res);
}
