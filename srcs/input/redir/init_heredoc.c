/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:41:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 23:15:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	complete_eof_name(char *eof_line, int *start, int *end, char **eof)
{
	int		len;
	char	*name;

	len = *end - *start;
	ft_printf("start: %c ; end: %c", eof_line[*start], eof_line[*end]);
	if (eof_line[*start] && len > 0 && (!is_quote(eof_line[*start])
			|| !is_quote(eof_line[*start + 1])))
	{
		name = ft_substr(eof_line, *start, len);
		*eof = heredoc_strjoin(*eof, name);
		free(name);
		*start = *end;
	}
	if (is_quote(eof_line[*end]))
	{
		*start = *end + 1;
		if (is_quote(eof_line[*start]))
			(*start)++;
	}
	*end = *start;
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

char	*set_eof_heredoc(char *eof_line, t_bool *expander_var)
{
	char		*eof;
	int			j;
	int			i;
	t_quote_dt	quote;

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
	t_quote_dt	quote;
	t_heredoc	*heredoc;
	int			eof_len;

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

t_heredoc	*get_all_heredoc(char *input)
{
	t_heredoc	*heredoc;
	t_heredoc	*list;
	t_quote_dt	quote;
	int			i;

	i = 0;
	init_quote_dt(&quote);
	list = NULL;
	while (input && *input && *(input + 1))
	{
		update_quote_dt(*input, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && *input == '<'
			&& *(input + 1) == '<')
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
