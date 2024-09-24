/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 11:18:00 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*rec;
	unsigned int	i;

	i = 0;
	rec = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			rec = (char *)s + i;
		i++;
	}
	if (rec)
		return (rec);
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
