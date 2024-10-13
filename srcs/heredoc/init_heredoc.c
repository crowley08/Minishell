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

void	set_exit_status_heredoc(t_msh *msh, int status, t_bool *has_stop)
{
	if (WIFEXITED(status))
	{
		msh->exit_status = EXIT_SUCCESS;
		*has_stop = TRUE;
		if (WEXITSTATUS(status) == HEREDOC_EOF)
		{
			ft_printf("msh: warning: here-document delimited by end-of-file \
			(wanted `eof')\n");
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

t_bool	has_heredoc_error(t_msh *msh, char *input)
{
	pid_t	pid_heredoc;
	t_bool	has_stop;
	int		status_heredoc;

	msh->heredoc = get_heredoc(input);
	if (msh->heredoc)
	{
		has_stop = FALSE;
		pid_heredoc = fork();
		if (pid_heredoc < 0)
			error_fork_heredoc(msh, input);
		else if (pid_heredoc == 0)
		{
			status_heredoc = launch_heredoc(msh);
			free_msh_heredoc(msh, input);
			exit(status_heredoc);
		}
		signal(SIGINT, SIG_IGN);
		waitpid(pid_heredoc, &status_heredoc, 0);
		set_exit_status_heredoc(msh, status_heredoc, &has_stop);
		if (has_stop)
		{
			error_heredoc(msh, input);
			return (TRUE);
		}
		// TODO: parse input with heredoc
	}
	// TODO: parse input with variable
	return (FALSE);
}
