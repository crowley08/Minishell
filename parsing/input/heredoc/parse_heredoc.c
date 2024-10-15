/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:00:24 by saandria          #+#    #+#             */
/*   Updated: 2024/10/15 15:52:14 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

int	launch_heredoc(t_msh *msh)
{
	t_error		error;
	t_heredoc	*heredoc;
	int			fd;

	error = NOTHING;
	heredoc = msh->heredoc;
	while (heredoc)
	{
		set_signal_handler_heredoc();
		fd = open(heredoc->tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0 && set_heredoc_error(&error, HEREDOC_FD))
			break ;
		error = create_file_heredoc(fd, msh, heredoc);
		if (error != NOTHING)
			break ;
		heredoc = heredoc->next;
	}
	return (error);
}

int	launch_heredoc_proc(t_msh *msh, char *input)
{
	int	exit_status;

	exit_status = launch_heredoc(msh);
	free_msh_heredoc(msh, input);
	return (exit_status);
}

void	set_exit_status_heredoc(t_msh *msh, int status, t_bool *has_stop)
{
	*has_stop = T;
	if (WIFEXITED(status))
	{
		msh->exit_status = EXIT_SUCCESS;
		if (WEXITSTATUS(status) == HEREDOC_EOF)
		{
			printf("msh: warning: heredoc delimited by end-of-file (`eof')\n");
			msh->exit_status = EXIT_SUCCESS;
		}
		else if (WEXITSTATUS(status) == HEREDOC_SIGINT)
			msh->exit_status = 130;
		else if (WEXITSTATUS(status) == HEREDOC_FD)
			msh->exit_status = EXIT_FAILURE;
		else
			*has_stop = F;
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = EXIT_FAILURE;
		*has_stop = T;
	}
}
