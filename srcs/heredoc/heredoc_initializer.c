/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:54:13 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 12:44:01 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_heredoc	*new_heredoc(void)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->eof = NULL;
	heredoc->tmp_file = NULL;
	heredoc->exp_var = TRUE;
	heredoc->next = NULL;
	return (heredoc);
}

t_heredoc	*create_heredoc(char **input, int i)
{
	t_heredoc	*heredoc;
	int			eof_len;

	heredoc = new_heredoc();
	if (!heredoc)
		return (NULL);
	heredoc->tmp_file = set_filename(i);
	eof_len = get_eof_len(*input);
	heredoc->eof = un_quote(ft_substr(*input, 0, eof_len), TRUE);
	heredoc->exp_var = has_to_expand_heredoc(ft_substr(*input, 0, eof_len));
	*input += eof_len;
	return (heredoc);
}

void	add_heredoc_list(t_heredoc **list, t_heredoc *heredoc)
{
	t_heredoc	*last;

	if (!(*list))
		*list = heredoc;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = heredoc;
	}
}

t_heredoc	*get_heredoc(char *input)
{
	t_heredoc	*list;
	t_heredoc	*heredoc;
	t_quote		quote;
	int			i;

	i = 0;
	list = NULL;
	init_quote(&quote);
	while (input && *input && *(input + 1))
	{
		update_quote(*input, &quote);
		if (quote_closed(quote) && *input == '<' && *(input + 1) == '<')
		{
			input += 2;
			if (ft_isspace(*input))
				input++;
			heredoc = create_heredoc(&input, i++);
			if (heredoc)
				add_heredoc_list(&list, heredoc);
		}
		else
			input++;
	}
	return (list);
}
