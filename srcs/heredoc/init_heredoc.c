/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+			+:+   */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:46:26 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 17:45:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void set_exit_status_heredoc(t_msh *msh, int status, t_bool *has_stop)
{
	*has_stop = TRUE;
	if (WIFEXITED(status))
	{
		msh->exit_status = EXIT_SUCCESS;
		if (WEXITSTATUS(status) == HEREDOC_EOF)
		{
			printf("msh: warning: here-document delimited by end-of-file (wanted `eof')\n");
			msh->exit_status = EXIT_SUCCESS;
		}
		else if (WEXITSTATUS(status) == HEREDOC_SIGINT)
			msh->exit_status = 130;
		else if (WEXITSTATUS(status) == HEREDOC_FD)
			msh->exit_status = EXIT_FAILURE;
		else
			*has_stop = FALSE;
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = EXIT_FAILURE;
		*has_stop = TRUE;
	}
}

int launch_heredoc_proc(t_msh *msh, char *input)
{
	int exit_status;

	exit_status = launch_heredoc(msh);
	free_msh_heredoc(msh, input);
	return (exit_status);
}

t_bool has_heredoc_parse_input_error(t_msh *msh, char *input)
{
	pid_t pid_heredoc;
	t_bool has_stop;
	int status_heredoc;

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
			return (TRUE);
		}
		input = parse_input_heredoc(msh->heredoc, input, TRUE);
	}
	msh->input = expand_input_var(msh, input, TRUE);
	return (FALSE);
}
