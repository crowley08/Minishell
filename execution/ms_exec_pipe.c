/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:11:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/21 10:47:33 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_left(int fd[2], t_node *node, t_msh *msh)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ms_exec(node->left, msh);
	return ;
}

static void	exec_right(int fd[2], t_node *node, t_msh *msh)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ms_exec(node->right, msh);
}

int	wait_pipe(int left, int right, int fd[2], int status)
{
	int	exit_status;

	exit_status = 0;
	close(fd[1]);
	close(fd[0]);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(left, NULL, 0);
	waitpid(right, &status, 0);
	printf("status :%d\n", status);
	if (WIFEXITED(status))
	{
		printf("ato\n");
		exit_status = WEXITSTATUS(status);
	}
	if (WIFSIGNALED(status))
	{
		exit_status = 128 + WTERMSIG(status);
		write(1, "\n", 1);
	}
	return (exit_status);
}

void	exec_pipe(t_node *node, t_msh *msh)
{
	int		fd[2];
	pid_t	right;
	pid_t	left;
	int		status;

	status = msh->exit_status;
	if (pipe(fd) == -1)
		error();
	right = 1;
	left = fork();
	if (left == 0)
		exec_left(fd, node, msh);
	else
	{
		right = fork();
		if (right == 0)
			exec_right(fd, node, msh);
	}
	msh->exit_status = wait_pipe(left, right, fd, status);
	printf("msh->exit_status: %d\n", msh->exit_status);
}
