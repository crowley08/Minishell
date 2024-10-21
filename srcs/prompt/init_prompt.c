/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:10:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 10:28:29 by arakotom         ###   ########.fr       */
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

t_prompt *parse_input_prompt(char **tab)
{
	t_prompt *list;
	t_prompt *prompt;
	int i;

	i = 0;
	list = NULL;
	while (tab && tab[i])
	{
		prompt = create_prompt(tab[i]);
		if (prompt)
			add_prompt_list(&list, prompt);
		i++;
	}
	return (list);
}

t_bool parse_token_prompt_ok(t_msh *msh)
{
	char **tab;

	tab = split_pipe(msh->input);
	if (!tab)
	{
		msh->exit_status = EXIT_FAILURE;
		return (free_msh_reset(msh, FALSE));
	}
	msh->prompt_list = parse_input_prompt(tab);
	ft_free_tab_str(tab);
	if (!(msh->prompt_list))
	{
		msh->exit_status = EXIT_FAILURE;
		return (free_msh_reset(msh, FALSE));
	}
	return (TRUE);
}
