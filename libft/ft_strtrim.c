/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:19 by saandria          #+#    #+#             */
/*   Updated: 2024/03/30 14:44:52 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s) - 1;
	while (end > start && ft_strchr(set, s[end]))
		end--;
	return (ft_substr(s, start, end - start + 1));
}
