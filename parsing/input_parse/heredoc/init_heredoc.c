/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:24:51 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:44:02 by saandria         ###   ########.fr       */
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
	heredoc->filename = NULL;
	heredoc->expend_var = TRUE;
	heredoc->next = NULL;
	return (heredoc);
}

char	*set_filename_heredoc(int i)
{
	char	*index;
	char	*name;

	index = ft_itoa(i);
	name = ft_strjoin(".tmp", index);
	free(index);
	return (name);
}

int	get_len_eof_line(char *input)
{
	int				len;
	t_quote_type	quote;

	len = 0;
	init_quote_dt(&quote);
	while (input && input[len] && !is_char_redir(input[len])
		&& !ft_isspace(input[len]) && input[len] != '|')
	{
		update_quote_dt(input[len], &quote);
		len++;
		while (quote.d_q == OPENED || quote.s_q == OPENED)
		{
			update_quote_dt(input[len], &quote);
			len++;
		}
	}
	return (len);
}

char	*set_eof_heredoc(char *eof_line, t_bool *expander_var)
{
	char			*eof;
	int				j;
	int				i;
	t_quote_type	quote;

	i = 0;
	j = 0;
	init_quote_dt(&quote);
	eof = ft_strdup("");
	while (eof_line && eof_line[i] && eof_line[j])
	{
		update_quote_dt(eof_line[j], &quote);
		while (eof_line[j] && quote.d_q == CLOSED && quote.s_q == CLOSED)
			update_quote_dt(eof_line[++j], &quote);
		if (is_quote(eof_line[j]))
			*expander_var = FALSE;
		complete_eof_name(eof_line, &i, &j, &eof);
		while (eof_line[j] && (quote.d_q == OPENED || quote.s_q == OPENED))
			update_quote_dt(eof_line[++j], &quote);
		complete_eof_name(eof_line, &i, &j, &eof);
	}
	free(eof_line);
	return (eof);
}

t_heredoc	*create_heredoc(char **input, int i)
{
	t_quote_type	quote;
	t_heredoc		*heredoc;
	int				eof_len;

	eof_len = 0;
	init_quote_dt(&quote);
	heredoc = new_heredoc();
	if (!heredoc)
		return (NULL);
	heredoc->filename = set_filename_heredoc(i);
	eof_len = get_len_eof_line(*input);
	heredoc->eof = set_eof_heredoc(ft_substr(*input, 0, eof_len),
			&(heredoc->expend_var));
	*input += eof_len;
	return (heredoc);
}
