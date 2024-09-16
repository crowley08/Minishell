/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:47:19 by saandria          #+#    #+#             */
/*   Updated: 2024/03/24 14:51:08 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return ((int)(tmp1[i] - tmp2[i]));
		i++;
	}
	return (0);
}
