/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:41:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 16:07:16 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_heredoc *new_heredoc(void)
{
	t_heredoc *heredoc;
	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->eof = NULL;
	heredoc->filename = NULL;
	heredoc->expend_var = TRUE;
	heredoc->next = NULL;
	return (heredoc);
}
char *set_filename(int i)
{
	char *index;
	char *name;

	index = ft_itoa(i);
	name = ft_strjoin(".tmp", index);
	free(index);
	return (name);
}

void add_heredoc_list(t_heredoc **list, t_heredoc *heredoc)
{
	t_heredoc *last;

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

t_heredoc *create_heredoc(char **input, int i)
{
	t_quote_dt quote;
	t_heredoc *heredoc;
	int eof_len;

	eof_len = 0;
	init_quote_dt(&quote);
	heredoc = new_heredoc();
	if (!heredoc)
		return (NULL);
	heredoc->filename = set_filename(i);
	while (input && *input && (*input)[eof_len] && !is_char_redir((*input)[eof_len]) && !ft_isspace((*input)[eof_len]))
	{
		eof_len++;
		update_quote_dt((*input)[eof_len], &quote);
		while (quote.d_q == OPENED || quote.s_q == OPENED)
		{
			eof_len++;
			update_quote_dt((*input)[eof_len], &quote);
		}
	}
	heredoc->eof = ft_substr(*input, 0, eof_len);
	heredoc->expend_var = TRUE;
	*input += eof_len;
	return (heredoc);
}

t_heredoc *get_all_heredoc(char *input)
{
	t_heredoc *heredoc;
	t_heredoc *list;
	t_quote_dt quote;
	int i;

	i = 0;
	init_quote_dt(&quote);
	list = NULL;
	while (input && *input && *(input + 1))
	{
		update_quote_dt(*input, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && *input == '<' && *(input + 1) == '<' && (input += 2))
		{
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

void print_heredoc(t_heredoc *heredoc)
{
	ft_printf("heredocs:\n");
	while (heredoc)
	{
		ft_printf("eof: %s\n", heredoc->eof);
		ft_printf("filename: %s\n", heredoc->filename);
		ft_printf("expend_var: %d\n", heredoc->expend_var);
		heredoc = heredoc->next;
	}
}
void free_heredoc(t_heredoc *heredoc)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->filename)
		free(heredoc->filename);
	free(heredoc);
}

void free_heredoc_list(t_heredoc **list)
{
	t_heredoc *heredoc;

    while (list && *list)
    {
        heredoc = *list;
        *list = (*list)->next;
        free_heredoc(heredoc);
    }
    *list = NULL;
}
