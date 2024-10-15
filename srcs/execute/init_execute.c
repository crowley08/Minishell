/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:27:03 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 14:53:11 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//! NOT DONE
t_bool execute_prompt_child(t_msh *msh, t_prompt *prompt)
{
	if (has_error_redir_exec(prompt))
		return (EXIT_FAILURE);
	else if (set_redir_std_in_out_error(prompt))
		return (EXIT_FAILURE);
	if (0)
		return (EXIT_SUCCESS);
	else
		return (exec_execve(msh, prompt->cmd));
}

t_bool execute_prompt_last(t_msh *msh, t_prompt *prompt, int stn_out)
{
	pid_t pid_exec_last;
	int status_exec_last;
	t_bool has_error;

	dup2(stn_out, STDOUT_FILENO);
	if (has_error_redir_exec(prompt))
		return (EXIT_FAILURE);
	else if (set_redir_std_in_out_error(prompt))
		return (EXIT_FAILURE);
	if (0)
		return (EXIT_SUCCESS);
	pid_exec_last = fork();
	if (pid_exec_last < 0)
		return (EXIT_FAILURE);
	else if (pid_exec_last == 0)
	{
		status_exec_last = exec_execve(msh, prompt->cmd);
		if (status_exec_last != EXECVE_FAILED)
			free_msh(msh);
		exit(status_exec_last);
	}
	waitpid(pid_exec_last, &status_exec_last, 0);
	set_exit_status_exec(msh, status_exec_last, &has_error);
	return (has_error);
}

void set_exit_status_exec(t_msh *msh, int status, t_bool *has_error)
{
	*has_error = FALSE;
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != EXIT_SUCCESS)
		{
			msh->exit_status = EXIT_FAILURE;
			*has_error = TRUE;
		}
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = WTERMSIG(status);
		*has_error = TRUE;
	}
	else
	{
		msh->exit_status = EXIT_FAILURE;
		*has_error = TRUE;
	}
}

int launch_exec_prompt_child(t_msh *msh, t_prompt *prompt)
{
	pid_t pid_exec;
	int fd[2];
	int status_exec;
	t_bool has_error;

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	pid_exec = fork();
	if (pid_exec < 0)
		return (EXIT_FAILURE);
	else if (pid_exec == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		status_exec = execute_prompt_child(msh, prompt);
		ft_printf(" status execve CHILD%d\n", status_exec);
		if (status_exec != EXECVE_FAILED)
			free_msh(msh);
		exit(status_exec);
	}
	waitpid(pid_exec, &status_exec, 0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	set_exit_status_exec(msh, status_exec, &has_error);
	return (has_error);
}

t_bool execute_prompts_list_error(t_msh *msh)
{
	t_prompt *prompt_list;
	int std_in;
	int std_out;
	t_bool has_error;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	prompt_list = msh->prompt_list;
	has_error = FALSE;
	while (prompt_list->next)
	{
		ft_printf("execute_prompts_list_error\n");
		has_error = launch_exec_prompt_child(msh, prompt_list);
		if (has_error)
			break;
		prompt_list = prompt_list->next;
	}
	if (has_error)
	{
		free_msh_reset(msh);
		return (TRUE);
	}
	ft_printf("execute_prompts_list_error last\n");
	has_error = execute_prompt_last(msh, prompt_list, std_out);
	if (has_error)
		free_msh_reset(msh);
	dup2(std_in, STDIN_FILENO);
	dup2(std_out, STDOUT_FILENO);
	close(std_in);
	close(std_out);
	return (has_error);
}
