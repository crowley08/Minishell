/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/21 10:50:43 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_built(char **cmd, char **env)
{
	if (!ft_strcmp(cmd[0], "pwd"))
		ms_pwd();
	else if (!ft_strcmp(cmd[0], "cd"))
		ms_cd(cmd, env);
	else if (!ft_strcmp(cmd[0], "env"))
		ms_env(env);
	return ;
}

void	exec(char **cmd, t_msh *msh)
{
	char	*path;

	if (cmd_is_builtin(cmd))
	{
		exec_built(cmd, msh->envc);
		free_minishell(msh);
		free_all(msh);
		exit (EXIT_SUCCESS);
	}
	else
	{
		path = check_path(cmd[0], msh->envc);
		if (!path)
		{
			free_spl(msh->envc);
			free_node(&msh->node);
			free_all(msh);
			error();
		}
		if (execve(path, cmd, msh->envc) == -1)
			error();
	}
}

void	ms_exec(t_node *node, t_msh *msh)
{
	if (node->type == CMD_NODE)
		exec(node->cmd, msh);
	else if (node->type == PIPE_NODE)
		exec_pipe(node, msh);
	else if (node->type == REDIR_OUT_NODE || node->type == APPEND_NODE)
		exec_dir(node, msh);
	else if (node->type == REDIR_IN_NODE)
		exec_redirin(node, msh);
}

static int	free_exec(t_msh *msh, int status)
{
	status = msh->exit_status;
	free_minishell(msh);
	free_env(&msh->envp);
	free(msh);
	return (status);
}

void	exec_main(t_msh *msh)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ms_exec(msh->node, msh);
		free_exec(msh, status);
		exit(status);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		msh->exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		msh->exit_status = 128 + WTERMSIG(status);
		write(1, "\n", 1);
	}
	ms_signal();
}
