/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:56:29 by saandria          #+#    #+#             */
/*   Updated: 2024/03/30 14:38:24 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_sub;
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_sub = ft_strlen(s) - start;
	if (len < len_sub)
		len_sub = len;
	sub = (char *)malloc(sizeof(char) * (len_sub + 1));
	if (!sub)
		return (NULL);
	while (i < len_sub)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
