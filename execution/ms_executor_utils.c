/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:38:31 by saandria          #+#    #+#             */
/*   Updated: 2024/10/10 15:04:03 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*check_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;
	char	*tmp_part;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp_part, cmd);
		free(tmp_part);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

int	cmd_is_builtin(char **cmd)
{
	if (!ft_strcmp(cmd[0], "cd") || !ft_strcmp(cmd[0], "pwd")
		|| !ft_strcmp(cmd[0], "export") || !ft_strcmp(cmd[0], "unset")
		|| !ft_strcmp(cmd[0], "env") || !ft_strcmp(cmd[0], "exit"))
		return (1);
	return (0);
}

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

void	exec_dir(t_node *node, t_msh *msh)
{
	int		fd;
	int		i;
	mode_t	mode;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
		node->right = node->right->left;
	else if (node->right->type == PIPE_NODE
		&& node->right->left->type != CMD_NODE)
		node->right = node->right->right;
	printf("%s\n", node->right->cmd[0]);
	fd = open(node->right->cmd[0], O_CREAT | O_RDWR | O_TRUNC, mode);
	if (fd == -1)
	{
		free_spl(msh->envc);
		free_node(&msh->node);
		free_all(msh);
		perror("open");
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(node->left, msh);
}
