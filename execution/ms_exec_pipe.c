/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:11:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:11:32 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_left(int fd[2], t_node *node, t_msh *msh)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ms_exec(node->left, msh);
	signal(SIGINT, SIG_IGN);
	ms_signal();
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
	int		status;

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
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		msh->exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		msh->exit_status = 128 + WTERMSIG(status);
		write(1, "\n", 1);
	}
}
