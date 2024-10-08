/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/08 15:55:27 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_left(int fd[2], t_node *node, char **env)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ms_exec(node->left, env);
}

static void	exec_right(int fd[2], t_node *node, char **env)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ms_exec(node->right, env);
}

void	exec_pipe(t_node *node, char **env)
{
	int		fd[2];
	pid_t	child;

	if (pipe(fd) == -1)
		error();
	child = fork();
	if (child == -1)
		error();
	else if (child == 0)
		exec_left(fd, node, env);
	else
		exec_right(fd, node, env);
	close(fd[1]);
	close(fd[0]);
	waitpid(child, NULL, 0);
}

void	ms_exec(t_node *node, char **env)
{
	if (node->type == CMD_NODE)
		exec(node->cmd, env);
	else if (node->type == PIPE_NODE)
		exec_pipe(node, env);
	else if (node->type == REDIR_OUT_NODE)
		exec_dir(node, env);
}

void	exec_main(t_msh *msh)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ms_exec(msh->node, msh->envc);
	waitpid(pid, NULL, 0);
}
