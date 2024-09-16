/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:14:32 by saandria          #+#    #+#             */
/*   Updated: 2024/04/01 11:12:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_word(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static int	count_char(const char *s, size_t i, char c)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static void	split_free(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**get_words(const char *s, char c, size_t i, char **split)
{
	size_t	j;
	int		index;

	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_substr(s, index, (count_char(s, index, c)));
			if (split[j] == NULL)
			{
				split_free(split, j);
				return (NULL);
			}
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	split = get_words(s, c, i, split);
	return (split);
}
