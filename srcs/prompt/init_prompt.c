/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:55:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 13:22:30 by arakotom         ###   ########.fr       */
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
	prompt->redir_in = NULL;
	prompt->redir_out = NULL;
	prompt->next = NULL;
	return (prompt);
}

int get_next_word_len(char *input)
{
	t_quote_dt quote;
	int len;

	init_quote_dt(&quote);
	len = 0;
	if (is_char_redir(input[len]))
	{
		len++;
		if (is_char_redir(input[len]))
			len++;
		return len;
	}
	while (input && input[len])
	{
		update_quote_dt(input[len], &quote);
		if (quote.d_q == OPENED || quote.s_q == OPENED || ft_isalnum(input[len]) || input[len] == '_' || is_quote(input[len]) || input[len] == '.')
			len++;
		else
			break;
	}
	return (len);
}

t_prompt *create_prompt(char *input)
{
	t_prompt *prompt;
	char *value;
	int len;

	prompt = new_prompt();
	if (!prompt || !input)
		return (NULL);
	len = 0;
	ft_printf("\ncreate_prompt from: $%s$\n", input);
	while (input && *input)
	{
		len = 0;
		len = get_next_word_len(input);
		if (!len)
			break;
		value = ft_substr(input, 0, len);
		ft_printf("word: $%s$\n", value);
		free(value);
		input += len;
		if (ft_isspace(*input))
			input++;
	}
	return (prompt);
}

t_bool set_prompt_data(t_data *data, char **input_tab)
{
	t_prompt *list;
	t_prompt *prompt;
	int i;
	if (!input_tab)
		return (FALSE);
	list = NULL;
	i = 0;
	while (input_tab && input_tab[i])
	{
		// TODO: create this function create_prompt
		prompt = create_prompt(input_tab[i]);
		free_prompt(prompt);
		// if (prompt)
		// 	// TODO: create this function add_prompt_list
		// 	add_prompt_list(&list, prompt);
		i++;
	}
	ft_free_tab_str(input_tab);
	// if (!list)
	// 	return (FALSE);
	data->prompt = list;
	return (TRUE);
}
