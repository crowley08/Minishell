/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:17:37 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:43:09 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	write_heredoc_input(int fd, char *input, t_bool exp_var, t_env *envp)
{
	char	*value;
	int		i;

	if (exp_var)
	{
		while (input && *input)
		{
			if (*input == '$')
			{
				i = 0;
				value = expander_var(++input, envp);
				write(fd, value, ft_strlen(value));
				while (input && input[i] && (ft_isalnum(input[i])
						|| input[i] == '_'))
					i++;
				input += i;
			}
			else
				write(fd, input++, 1);
		}
	}
	else
		write(fd, input, ft_strlen(input));
}

char	*re_new_input_heredoc(char *old_input, char *input, t_heredoc **list)
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

char	*get_new_input_heredoc(char *input, t_heredoc *list, t_bool do_free)
{
	char			*new_input;
	int				i;
	t_quote_type	quote;

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
			new_input = re_new_input_heredoc(new_input, 0, &list);
		}
		else
			new_input = re_new_input_heredoc(new_input, input + i++, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
}

t_heredoc	*get_all_heredoc(char *input)
{
	t_heredoc		*heredoc;
	t_heredoc		*list;
	t_quote_type	quote;
	int				i;

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
