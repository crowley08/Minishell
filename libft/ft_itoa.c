/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:43:27 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/22 12:14:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbr_len(long n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr_str;
	long			nbr;
	unsigned int	nbr_len;
	unsigned int	is_neg;

	nbr = n;
	nbr_len = ft_nbr_len(nbr);
	is_neg = 0;
	nbr_str = (char *)ft_calloc(nbr_len + 1, sizeof(char));
	if (!nbr_str)
		return (NULL);
	if (nbr < 0)
	{
		nbr_str[0] = '-';
		is_neg = 1;
		nbr *= -1;
	}
	nbr_str[nbr_len] = '\0';
	while (nbr_len > is_neg)
	{
		nbr_str[nbr_len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		nbr_len--;
	}
	return (nbr_str);
}
