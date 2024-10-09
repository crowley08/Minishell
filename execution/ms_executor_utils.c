/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:38:31 by saandria          #+#    #+#             */
/*   Updated: 2024/10/09 08:00:36 by saandria         ###   ########.fr       */
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
		i++;
	}
	free(path);
	i = 0;
	while (paths[++i])
		free(paths[i]);
	return (0);
}

/*
			printf("%s\taccess autorised\n", path);
	printf("%s\taccess unautorised\n", path);
*/

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

void	exec(char **cmd, char **env)
{
	char	*path;

	if (cmd_is_builtin(cmd))
		exec_built(cmd, env);
	else
	{
		path = check_path(cmd[0], env);
		if (!path)
		{
			free_spl(cmd);
			error();
		}
		if (execve(path, cmd, env) == -1)
			error();
	}
}

void	exec_dir(t_node *node, char **env)
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
		perror("open");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(node->left, env);
}
