/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 15:25:21 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_left(int fd[2], t_node *node, t_msh *msh)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ms_exec(node->left, msh);
}

static void	exec_right(int fd[2], t_node *node, t_msh *msh)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ms_exec(node->right, msh);
}

void	exec_pipe(t_node *node, t_msh *msh)
{
	int		fd[2];
	pid_t	child;

	if (pipe(fd) == -1)
		error();
	child = fork();
	if (child == -1)
		error();
	else if (child == 0)
		exec_left(fd, node, msh);
	else
		exec_right(fd, node, msh);
	close(fd[1]);
	close(fd[0]);
	wait(NULL);
}

void	ms_exec(t_node *node, t_msh *msh)
{
	if (node->type == CMD_NODE)
		exec(node->cmd, msh);
	else if (node->type == PIPE_NODE)
		exec_pipe(node, msh);
	else if (node->type == REDIR_OUT_NODE)
		exec_dir(node, msh);
	else if (node->type == APPEND_NODE)
		exec_append(node, msh);
}

void	exec_main(t_msh *msh)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ms_exec(msh->node, msh);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		write(1, "\n", 1);
	ms_signal();
}
