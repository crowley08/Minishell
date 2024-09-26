/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:51:37 by saandria          #+#    #+#             */
/*   Updated: 2024/09/26 11:04:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while ((i < len && big[i] != '\0'))
	{
		if (big[i] == little[0])
		{
			if ((ft_strncmp(big + i, little, ft_strlen(little)) == 0)
				&& i + ft_strlen(little) <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
