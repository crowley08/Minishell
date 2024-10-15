/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:22:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/15 16:04:43 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	execve_redir(char *path, char **cmd, char **env)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmd, env) == -1)
		{
			free(path);
			error();
		}
	}
	waitpid(pid, &status, 0);
	return ;
}

static char	*ms_redir_succ(t_msh *msh, t_node *node, int flags, char *path)
{
	int		fd;
	mode_t	mode;
	char	*file;

	file = NULL;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	while (node && is_rout_or_append(node->right->type))
	{
		file = ft_strdup(node->right->left->cmd[0]);
		fd = open(file, flags, mode);
		if (fd == -1)
			free_if_fd_invalid(msh, file, path);
		free(file);
		if (node->right->left->cmd[1])
			execve_redir(path, node->right->left->cmd, msh->envc);
		node = node->right;
	}
	file = ft_strdup(node->right->cmd[0]);
	if (node->right->cmd[1])
		execve_redir(path, node->right->cmd, msh->envc);
	return (file);
}

static char	*ms_redir_out(t_msh *msh, t_node *node, int flags, char *path)
{
	char	*file;

	file = NULL;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
	{
		file = ft_strdup(node->right->left->cmd[0]);
		if (node->right->left->cmd[1])
			execve_redir(path, node->right->left->cmd, msh->envc);
	}
	else if (is_rout_or_append(node->right->type))
		file = ms_redir_succ(msh, node, flags, path);
	else
	{
		file = ft_strdup(node->right->cmd[0]);
		if (node->right->cmd[1])
			execve_redir(path, node->right->cmd, msh->envc);
	}
	free(path);
	return (file);
}

void	exec_dir(t_node *node, t_msh *msh)
{
	int		fd;
	mode_t	mode;
	char	*file;
	int		flags;
	char	*path;

	path = check_path(node->left->cmd[0], msh->envc);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->type == APPEND_NODE)
		flags = O_CREAT | O_RDWR | O_APPEND ;
	else
		flags = O_CREAT | O_RDWR | O_TRUNC ;
	file = ms_redir_out(msh, node, flags, path);
	printf("%s\n", file);
	fd = open(file, flags, mode);
	if (fd == -1)
		free_if_fd_invalid(msh, file, path);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	free(file);
	ms_exec(node->left, msh);
	free(path);
}
