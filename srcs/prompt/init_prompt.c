/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:55:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 10:50:29 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_prompt	*new_prompt(void)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
		return (NULL);
	prompt->cmd = NULL;
	prompt->redir_in = NULL;
	prompt->redir_out = NULL;
	prompt->next = NULL;
	return (prompt);
}

t_prompt	*create_prompt(char *input)
{
	t_prompt	*prompt;
	char		*value;
	int			len;

	prompt = new_prompt();
	if (!prompt || !input)
		return (NULL);
	while (input && *input)
	{
		len = 0;
		len = get_next_word_len(input);
		if (!len)
			break ;
		value = ft_substr(input, 0, len);
		input += len;
		if (ft_isspace(*input))
			input++;
		input += fill_prompt_token(&prompt, value, input);
		if (ft_isspace(*input))
			input++;
		free(value);
	}
	return (prompt);
}

void	add_prompt_list(t_prompt **list, t_prompt *prompt)
{
	t_prompt	*last;

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

t_bool	set_prompt_data(t_data *data, char **input_tab)
{
	t_prompt	*list;
	t_prompt	*prompt;
	int			i;

	if (!input_tab)
		return (FALSE);
	list = NULL;
	i = 0;
	while (input_tab && input_tab[i])
	{
		prompt = create_prompt(input_tab[i]);
		if (prompt)
			add_prompt_list(&list, prompt);
		i++;
	}
	ft_free_tab_str(input_tab);
	if (!list)
		return (FALSE);
	data->prompt = list;
	return (TRUE);
}
