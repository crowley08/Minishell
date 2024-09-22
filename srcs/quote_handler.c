/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:57:36 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 16:28:51 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quote_update_state(char c, t_quote_data *q_data)
{
	if (ms_is_quote(c) && q_data->d_q == CLOSED && q_data->s_q == CLOSED)
	{
		if (c == '"')
			q_data->d_q = OPENED;
		else if (c == '\'')
			q_data->s_q = OPENED;
	}
	else if (ms_is_quote(c) && (q_data->d_q == OPENED || q_data->s_q == OPENED))
	{
		if (c == '"')
			q_data->d_q = CLOSED;
		else if (c == '\'')
			q_data->s_q = CLOSED;
	}
}

t_bool	quote_opened(char *prompt)
{
	int				i;
	t_quote_data	q_data;

	i = 0;
	quote_init_state(&q_data);
	while (prompt && prompt[i])
	{
		if (ms_is_quote(prompt[i]))
			quote_update_state(prompt[i], &q_data);
		i++;
	}
	if (q_data.d_q == OPENED || q_data.s_q == OPENED)
		return (TRUE);
	return (FALSE);
}

char	*get_all_prompt(void)
{
	char	*p_left;
	char	*all_prompt;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf(pwd);
	all_prompt = readline(" > ");
	while (!all_prompt || !all_prompt[0])
	{
		free(all_prompt);
		ft_printf(pwd);
		all_prompt = readline(" > ");
	}
	free(pwd);
	while (quote_opened(all_prompt))
	{
		p_left = readline("> ");
		all_prompt = ft_strjoin(all_prompt, "\n");
		all_prompt = ft_strjoin(all_prompt, p_left);
		free(p_left);
	}
	return (all_prompt);
}
