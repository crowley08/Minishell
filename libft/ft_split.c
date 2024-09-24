/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:45:01 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 11:17:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (count);
}

static int	ft_next_word(char **tab_word, char *str, char sep, int word_index)
{
	int	word_len;
	int	i;

	word_len = 0;
	i = 0;
	while (str[word_len] && str[word_len] != sep)
		word_len++;
	tab_word[word_index] = (char *)malloc((size_t)(word_len + 1)
			* sizeof(char));
	if (!tab_word[word_index])
	{
		ft_free_tab_str(tab_word);
		return (0);
	}
	while (i < word_len)
	{
		tab_word[word_index][i] = str[i];
		i++;
	}
	tab_word[word_index][i] = '\0';
	return (word_len);
}

static int	ft_split_str(char **tab_word, char *str, char sep)
{
	int	i;
	int	word_len;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
		{
			word_len = ft_next_word(tab_word, &str[i], sep, word_index++);
			if (!word_len)
				return (0);
			i += word_len;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**tab_word;
	int		tab_len;

	tab_len = ft_count_words((char *)s, c);
	tab_word = (char **)malloc((size_t)(tab_len + 1) * sizeof(char *));
	if (!tab_word)
		return (NULL);
	if (!ft_split_str(tab_word, (char *)s, c))
		return (NULL);
	tab_word[tab_len] = NULL;
	return (tab_word);
}
