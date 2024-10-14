/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:06:20 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 11:36:53 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_prompt *new_prompt(void)
{
	t_prompt *prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
		return (NULL);
	prompt->cmd = NULL;
	prompt->redir_in_list = NULL;
	prompt->redir_out_list = NULL;
	prompt->next = NULL;
	return (prompt);
}

int next_value_len(char *input)
{
	int len;
	t_quote_dt quote;

	len = 0;
	if (is_redir(input[len]))
	{
		len++;
		if (is_redir(input[len]) && input[len] == input[len - 1])
			len++;
		return (len);
	}
	init_quote(&quote);
	while (input && input[len])
	{
		update_quote(input[len], &quote);
		if (quote_closed(quote) && (ft_isspace(input[len]) || is_redir(input[len])))
			break;
		len++;
	}
	return (len);
}

t_prompt *create_prompt(char *input)
{
	t_prompt *prompt;
	char *value;
	int len;

	prompt = new_prompt();
	if (!prompt)
		return (NULL);
	while (input && *input)
	{
		len = next_value_len(input);
		if (!len)
			break;
		value = ft_substr(input, 0, len);
		input += len;
		if (ft_isspace(*input))
			input++;
		input += set_prompt_token(&prompt, value, input);
		if (ft_isspace(*input))
			input++;
		free(value);
	}
	return (prompt);
}

void add_prompt_list(t_prompt **list, t_prompt *prompt)
{
	t_prompt *last;

	if (!list || !(*list))
		*list = prompt;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = prompt;
	}
}

t_prompt *parse_prompt(char **tab)
{
	t_prompt *list;
	t_prompt *prompt;
	int i;

	list = NULL;
	i = 0;
	while (tab && tab[i])
	{
		prompt = create_prompt(tab[i]);
		if (prompt)
			add_prompt_list(&list, prompt);
		i++;
	}
	return (list);
}
