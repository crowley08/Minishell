/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:45:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:35:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_exit_status_msh_hdc(t_msh *msh, t_error_state exit_status,
		t_bool *has_stop)
{
	*has_stop = FALSE;
	if (WIFEXITED(exit_status))
	{
		if (WEXITSTATUS(exit_status) != NOTHING)
		{
			*has_stop = TRUE;
			if (WEXITSTATUS(exit_status) == HDC_CTRL_D)
				msh->exit_status = 0;
			else if (WEXITSTATUS(exit_status) == HDC_CTRL_C)
				msh->exit_status = 130;
			else
				msh->exit_status = EXIT_FAILURE;
		}
	}
	else if (WIFSIGNALED(exit_status))
	{
		*has_stop = TRUE;
		msh->exit_status = WTERMSIG(exit_status);
	}
}

void	run_heredoc(t_msh *msh)
{
	t_error_state	error;

	error = check_parser_heredoc(msh);
	free_msh_keep_file(msh, TRUE);
	if (error == NOTHING)
		exit(EXIT_SUCCESS);
	print_err_hdc(error);
	exit(error);
}

t_bool	heredoc_parse_input_ok(t_msh *msh)
{
	pid_t	pid_hdc;
	int		exit_status_hdc;
	t_bool	has_stop;

	msh->heredoc_list = get_heredoc(msh->input);
	if (msh->heredoc_list)
	{
		pid_hdc = fork();
		if (pid_hdc < 0)
			exit_err_fork(msh);
		else if (pid_hdc == 0)
			run_heredoc(msh);
		signal(SIGINT, SIG_IGN);
		waitpid(pid_hdc, &exit_status_hdc, 0);
		set_exit_status_msh_hdc(msh, exit_status_hdc, &has_stop);
		if (has_stop)
			return (free_msh_reset(msh, FALSE));
		msh->input = parse_input_heredoc(msh->heredoc_list, msh->input, TRUE);
	}
	msh->input = expand_input_var(msh, msh->input, TRUE);
	return (TRUE);
}
