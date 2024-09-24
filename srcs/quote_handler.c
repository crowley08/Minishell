/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:57:36 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 23:35:48 by arakotom         ###   ########.fr       */
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

t_bool	pipe_location_valid(char *prompt)
{
	char	*p_trimmed;
	int		len;
	t_bool	res_state;

	res_state = TRUE;
	p_trimmed = ms_trim_free(ft_strdup(prompt));
	if (!p_trimmed)
		res_state = FALSE;
	len = ft_strlen(p_trimmed) - 1;
	if (res_state == TRUE && p_trimmed[0] == '|')
		res_state = ERROR;
	if (res_state == TRUE && p_trimmed[len] == '|')
	{
		res_state = FALSE;
		while (len > 0 && ft_isspace(p_trimmed[--len]))
			;
		if (len > 0 && p_trimmed[len] == '|')
		{
			while (len > 0 && ft_isspace(p_trimmed[--len]))
				;
			if (len > 0 && p_trimmed[len] == '|')
				res_state = ERROR;
		}
	}
	free(p_trimmed);
	return (res_state);
}

char	*get_all_input(void)
{
	char	*prompt_left;
	char	*all_prompt;

	all_prompt = readline("minishell > ");
	// verification si le prompt est une ligne vide
	while (!all_prompt || !all_prompt[0])
	{
		free(all_prompt);
		all_prompt = readline(" > ");
	}
	if (pipe_location_valid(all_prompt) == ERROR)
	{
		free(all_prompt);
		return (NULL);
	}
	// verification si les quotes sont fermées
	while (quote_opened(all_prompt) || pipe_location_valid(all_prompt) != TRUE)
	{
		prompt_left = readline("> ");
		if (quote_opened(all_prompt))
			all_prompt = ft_strjoin(all_prompt, "\n");
		else if (pipe_location_valid(all_prompt) == FALSE)
			all_prompt = ft_strjoin(all_prompt, " ");
		all_prompt = ft_strjoin(all_prompt, prompt_left);
		free(prompt_left);
		if (pipe_location_valid(all_prompt) == ERROR)
			return (NULL);
	}
	return (all_prompt);
}
