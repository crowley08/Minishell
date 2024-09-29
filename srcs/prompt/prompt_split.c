/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:04:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/29 23:01:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_pipes(char *str)
{
	int			count;
	t_quote_dt	quote;

	count = 0;
	init_quote_dt(&quote);
	while (str && *str)
	{
		if (*str != '|')
			count++;
		while (*str && (*str != '|' || quote.d_q == OPENED
				|| quote.s_q == OPENED))
			update_quote_dt(*(str++), &quote);
		if (*str)
			str++;
	}
	return (count);
}

static int	set_next_split_pipe(char **tab, char *str, int index)
{
	int			len;
	int			space_fount;
	t_quote_dt	quote;

	len = 0;
	space_fount = 0;
	init_quote_dt(&quote);
	while (str[len] && (str[len] != '|' || quote.d_q == OPENED
			|| quote.s_q == OPENED))
		update_quote_dt(str[len++], &quote);
	if (!len)
		return (0);
	if (str[len] && len > 0 && ft_isspace(str[len - 1]))
		space_fount = 1;
	tab[index] = ft_substr(str, 0, len - space_fount);
	if (!tab[index])
		return (0);
	return (len);
}

static t_bool	pipe_splitted(char **tab, char *str)
{
	int	index;
	int	len;

	index = 0;
	while (str && *str)
	{
		if (*str == '|')
			if (ft_isspace(*(++str)))
				str++;
		if (*str)
		{
			len = set_next_split_pipe(tab, str, index++);
			if (!len)
				return (FALSE);
			str += len;
		}
	}
	return (TRUE);
}

char	**split_pipe(char *str)
{
	char	**tab;
	int		len;

	if (!is_trimmed(str))
		str = trim_space_all(str);
	len = count_pipes(str);
	if (!len)
		return (NULL);
	tab = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!tab)
		return (NULL);
	if (!pipe_splitted(tab, str))
	{
		ft_free_tab_str(tab);
		free(str);
		return (NULL);
	}
	free(str);
	tab[len] = NULL;
	return (tab);
}
