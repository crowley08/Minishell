/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_split_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:38:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 09:41:34 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_pipe(char *input)
{
	int count;
	t_quote quote;

	count = 0;
	init_quote(&quote);
	while (input && *input)
	{
		if (*input != '|')
			count++;
		while (*input && (*input != '|' || quote_opened(quote)))
			update_quote(*(input++), &quote);
		if (*input)
			input++;
	}
	return (count);
}

int set_next_pipe(char **tab, char *input, int tab_index)
{
	int len;
	t_quote quote;
	int found_space;

	len = 0;
	found_space = 0;
	init_quote(&quote);
	while (input[len] && (input[len] != '|' || quote_opened(quote)))
		update_quote(input[len++], &quote);
	if (!len)
		return (0);
	if (input[len] && ft_isspace(input[len - 1]))
		found_space = 1;
	tab[tab_index] = ft_substr(input, 0, len - found_space);
	if (!tab[tab_index])
		return (0);
	return (len);
}

t_bool pipe_splitted(char **tab, char *input)
{
	int tab_index;
	int len;

	tab_index = 0;
	while (input && *input)
	{
		if (*input == '|')
			if (ft_isspace(*(++input)))
				input++;
		if (*input)
		{
			len = set_next_pipe(tab, input, tab_index++);
			if (!len)
				return (FALSE);
			input += len;
		}
	}
	return (TRUE);
}

char **split_pipe(char *input)
{
	char **tab;
	int tab_len;

	tab_len = count_pipe(input);
	if (!tab_len)
		return (NULL);
	tab = (char **)ft_calloc(sizeof(char *), tab_len + 1);
	if (!tab)
		return (NULL);
	if (!pipe_splitted(tab, input))
	{
		ft_free_tab_str(tab);
		return (NULL);
	}
	tab[tab_len] = NULL;
	return (tab);
}
