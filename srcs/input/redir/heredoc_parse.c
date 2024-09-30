/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 00:41:57 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool	fill_file_input(int fd, t_heredoc heredoc)
{
	char	*input;

	while (42)
	{
		rl_on_new_line();
		input = readline("> ");
		if (!input || is_empty_line(input))
		{
			free(input);
			write(fd, "\n", 1);
			continue ;
		}
		else
		{
			if (ft_strncmp(input, heredoc.eof, ft_strlen(input)) == 0)
			{
				free(input);
				return (TRUE);
			}
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		free(input);
	}
}

t_bool	create_file_heredoc(t_heredoc *list)
{
	int	fd;

	while (list)
	{
		fd = open(list->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (FALSE);
		if (!fill_file_input(fd, *list))
		{
			unlink(list->filename);
			return (FALSE);
		}
		close(fd);
		list = list->next;
	}
	return (TRUE);
}

int	get_len_eof_line(char *input)
{
	int			len;
	t_quote_dt	quote;

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

int	get_len_new_input(char *input, t_heredoc *list)
{
	int			len;
	t_quote_dt	quote;

	len = 0;
	init_quote_dt(&quote);
	while (input && *input && *(input + 1))
	{
		update_quote_dt(*input, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && *input == '<'
			&& *(input + 1) == '<')
		{
			input += 2;
			if (ft_isspace(*input))
				input++;
			len += ft_strlen(list->filename) + 2;
		}
	}
	return (len);
}
