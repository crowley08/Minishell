/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:13:52 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:14:22 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_heredoc	*new_heredoc(void)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->eof = NULL;
	heredoc->tmp_file = NULL;
	heredoc->exp_var = T;
	heredoc->next = NULL;
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

t_heredoc	*create_heredoc(char **input, int i)
{
	t_heredoc	*heredoc;
	int			eof_len;

	heredoc = new_heredoc();
	if (!heredoc)
		return (NULL);
	heredoc->tmp_file = set_filename(i);
	eof_len = get_eof_len(*input);
	heredoc->eof = un_quote(ft_substr(*input, 0, eof_len), T);
	heredoc->exp_var = has_to_expand_heredoc(ft_substr(*input, 0, eof_len));
	*input += eof_len;
	return (heredoc);
}
