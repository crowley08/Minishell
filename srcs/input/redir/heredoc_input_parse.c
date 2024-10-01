/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_input_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 22:58:12 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool	fill_file_input(int fd, t_heredoc heredoc, t_env *envp)
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
			// write(fd, input, ft_strlen(input));
			write_heredoc_input(fd, input, heredoc.expend_var, envp);
			write(fd, "\n", 1);
		}
		free(input);
	}
}

t_bool	create_file_heredoc(t_heredoc *list, t_env *envp)
{
	int	fd;

	while (list)
	{
		fd = open(list->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (FALSE);
		if (!fill_file_input(fd, *list, envp))
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

char	*re_new_input(char *old_input, char *input, t_heredoc **list)
{
	char	*c;

	if (list && *list)
	{
		old_input = heredoc_strjoin(old_input, "<");
		old_input = heredoc_strjoin(old_input, (*list)->filename);
		*list = (*list)->next;
	}
	else if (input && *input)
	{
		c = ft_substr(input, 0, 1);
		old_input = heredoc_strjoin(old_input, c);
		free(c);
	}
	return (old_input);
}

char	*get_new_input_heredoc(char *input, t_heredoc *list)
{
	char		*new_input;
	int			i;
	t_quote_dt	quote;

	new_input = NULL;
	i = 0;
	init_quote_dt(&quote);
	while (input && input[i])
	{
		update_quote_dt(input[i], &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && input[i] == '<'
			&& input[i + 1] == '<')
		{
			i += 2;
			if (ft_isspace(input[i]))
				i++;
			i += get_len_eof_line(input + i);
			new_input = re_new_input(new_input, 0, &list);
		}
		else
			new_input = re_new_input(new_input, input + i++, NULL);
	}
	free(input);
	return (new_input);
}
