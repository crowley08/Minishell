/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:14:50 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:56:44 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*re_new_input_var(char *old_input, char *input, int *i, t_msh *msh)
{
	int		len;
	char	*tmp_c;
	char	*value;

	if (msh && msh->envp)
	{
		*i += 1;
		value = expand_var_heredoc(input + *i, msh);
		old_input = msh_strjoin(old_input, value);
		free(value);
		len = 0;
		while (input && input[*i + len] && (ft_isalnum(input[*i + len])
				|| input[*i + len] == '_'))
			len++;
		*i += len;
	}
	else if (input && *input)
	{
		tmp_c = ft_substr(input + *i, 0, 1);
		old_input = msh_strjoin(old_input, tmp_c);
		free(tmp_c);
		*i += 1;
	}
	return (old_input);
}

char	*re_new_input_heredoc(char *old_input, char *input, t_heredoc **list)
{
	char	*tmp_c;

	if (list && *list)
	{
		old_input = msh_strjoin(old_input, "<");
		old_input = msh_strjoin(old_input, (*list)->tmp_file);
		(*list) = (*list)->next;
	}
	else if (input && *input)
	{
		tmp_c = ft_substr(input, 0, 1);
		old_input = msh_strjoin(old_input, tmp_c);
		free(tmp_c);
	}
	return (old_input);
}

char	*parse_input_heredoc(t_heredoc *list, char *input, t_bool do_free)
{
	int		i;
	char	*new_input;
	t_quote	quote;

	i = 0;
	new_input = NULL;
	init_quote(&quote);
	while (input && input[i])
	{
		update_quote(input[i], &quote);
		if (quote_closed(quote) && input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			if (ft_isspace(input[i]))
				i++;
			i += get_eof_len(input + i);
			new_input = re_new_input_heredoc(new_input, 0, &list);
		}
		else
			new_input = re_new_input_heredoc(new_input, input + i++, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
}

t_bool	has_heredoc_parse_input_error(t_msh *msh, char *input)
{
	pid_t	pid_heredoc;
	t_bool	has_stop;
	int		status_heredoc;

	msh->heredoc = get_heredoc(input);
	if (msh->heredoc)
	{
		pid_heredoc = fork();
		if (pid_heredoc < 0)
			error_fork_heredoc(msh, input);
		else if (pid_heredoc == 0)
			exit(launch_heredoc_proc(msh, input));
		signal(SIGINT, SIG_IGN);
		waitpid(pid_heredoc, &status_heredoc, 0);
		set_exit_status_heredoc(msh, status_heredoc, &has_stop);
		if (has_stop)
		{
			error_heredoc(msh, input);
			return (T);
		}
		input = parse_input_heredoc(msh->heredoc, input, T);
	}
	msh->input = expand_input_var(msh, input, T);
	return (F);
}
