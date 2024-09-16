/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:28:32 by saandria          #+#    #+#             */
/*   Updated: 2024/03/24 14:36:05 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = (void *)0;
	while (*s)
	{
		if (*(char *)s == (char)c)
			occ = (char *) s;
		s++;
	}
	if ((char)c == '\0')
	{
		if (*(char *)s == '\0')
			return ((char *) s);
	}
	return (occ);
}
