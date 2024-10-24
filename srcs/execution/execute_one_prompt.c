/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:12:50 by saandria          #+#    #+#             */
/*   Updated: 2024/10/24 12:31:02 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_one_prompt(t_msh *msh, t_prompt *prompt)
{
	pid_t	pid_one_pmt;
	int		exit_status_one;

	if (cmd_is_builtin(prompt->cmd))
	{
		exit_status_one = ms_exec_builtin(msh, prompt->cmd);
		set_exit_status_msh_exec_one_last_cmd(msh, exit_status_one);
	}
	else
	{
		pid_one_pmt = fork();
		if (pid_one_pmt < 0)
			exit_err_pipe(msh);
		else if (pid_one_pmt == 0)
		{
			signal(SIGINT, SIG_DFL);
			dup2(msh->std_out, STDOUT_FILENO);
			exit(execute_cmd_in_list(msh, prompt));
		}
		signal(SIGINT, SIG_IGN);
		waitpid(pid_one_pmt, &exit_status_one, 0);
		set_signal_handler();
		set_exit_status_msh_exec_one_last_cmd(msh, exit_status_one);
	}
}
