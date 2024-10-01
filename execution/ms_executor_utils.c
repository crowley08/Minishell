/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:38:31 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 22:51:44 by saandria         ###   ########.fr       */
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

void	exec(char **cmd, char **env)
{
	char	*path;

	path = check_path(cmd[0], env);
	if (!path)
	{
		free_spl(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
		error();
}

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
