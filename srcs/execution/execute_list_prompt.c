/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:28:37 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 15:50:01 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void set_exit_status_msh_exec_one_last_cmd(t_msh *msh, int exit_status)
{
	if (WIFEXITED(exit_status))
		msh->exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		msh->exit_status = 128 + exit_status;
	else
		msh->exit_status = exit_status;
}

void execute_last_cmd_in_list(t_msh *msh, t_prompt *prompt)
{
	pid_t pid_exec_last;
	int exit_status_last;

	pid_exec_last = fork();
	if (pid_exec_last < 0)
		exit_err_pipe(msh);
	else if (pid_exec_last == 0)
	{
		signal(SIGINT, SIG_DFL);
		dup2(msh->std_out, STDOUT_FILENO);
		exit(execute_cmd_in_list(msh, prompt));
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid_exec_last, &exit_status_last, 0);
	set_signal_handler();
	set_exit_status_msh_exec_one_last_cmd(msh, exit_status_last);
	while (wait(NULL) > 0)
		;
}

void execute_list_prompt(t_msh *msh, t_prompt *list)
{
	pid_t pid_exec_list;
	int fd[2];

	while (list->next)
	{
		if (pipe(fd) < 0)
			exit_err_pipe(msh);
		pid_exec_list = fork();
		if (pid_exec_list < 0)
			exit_err_fork(msh);
		else if (pid_exec_list == 0)
		{
			signal(SIGINT, SIG_DFL);
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			exit(execute_cmd_in_list(msh, list));
		}
		waitpid(pid_exec_list, NULL, WNOHANG);
		signal(SIGINT, SIG_IGN);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		list = list->next;
	}
	execute_last_cmd_in_list(msh, list);
}
