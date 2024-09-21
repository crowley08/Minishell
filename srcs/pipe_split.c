/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:21:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 00:17:40 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_count_prompt(char *str)
{
	int				count;
	t_quote_data	q_data;

	count = 0;
	quote_init_state(&q_data);
	while (str && *str)
	{
		if (*str != '|')
			count++;
		while (*str && (*str != '|' || (q_data.d_q == OPENED
					|| q_data.s_q == OPENED)))
			quote_update_state(*(str++), &q_data);
		if (*str)
			str++;
	}
	return (count);
}

static int	ms_next_split(char **tab, char *str, int index)
{
	int				len;
	int				sp_found;
	t_quote_data	q_data;

	len = 0;
	sp_found = 0;
	quote_init_state(&q_data);
	while (str[len] && (str[len] != '|' || (q_data.d_q == OPENED
				|| q_data.s_q == OPENED)))
		quote_update_state(str[len++], &q_data);
	if (str[len] && str[len - 1] == ' ')
		sp_found = 1;
	tab[index] = ft_substr(str, 0, len - sp_found);
	if (!tab[index])
	{
		ft_free_tab_str(tab);
		return (0);
	}
	return (len);
}

static t_bool	ms_splitted_pipe(char **tab, char *str)
{
	int	index;
	int	i;
	int	len;

	i = 0;
	index = 0;
	while (str && str[i])
	{
		if (str[i] == '|')
		{
			if (str[i + 1] == ' ')
				i++;
			i++;
		}
		if (str[i])
		{
			len = ms_next_split(tab, &str[i], index++);
			if (!len)
				return (FALSE);
			i += len;
		}
	}
	return (TRUE);
}
// str must already trimmed, use [*ms_trim_free(char *)]
char	**ms_split_pipe(char *str)
{
	char	**tab;
	int		tab_len;

	tab_len = ms_count_prompt(str);
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!tab)
		return (NULL);
	if (!ms_splitted_pipe(tab, str))
		return (NULL);
	tab[tab_len] = NULL;
	return (tab);
}
