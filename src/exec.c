/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 12:16:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_spl(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

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
		{
			printf("%s\taccess autorised\n", path);
			return (path);
		}
		i++;
	}
	printf("%s\taccess unautorised\n", path);
	free(path);
	i = 0;
	while (paths[++i])
		free(paths[i]);
	return (0);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	exec(char **cmd, char **env)
{
	char	*path;

	path = check_path(cmd[0], env);
	printf("%s\n", path);
	if (!path)
	{
		free_spl(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
		error();
}

void	exec_pipe(t_node **node, char **env)
{
	int	fd[2];
	pid_t	child;

	if (!*node)
		return ;
	if ((*node)->type == CMD_NODE)
		exec((*node)->cmd, env);
	else if ((*node)->type == PIPE_NODE)
	{
		if (pipe(fd) == -1)
	    error();
		child = fork();
		if (child == -1)
			error();
		else if (child == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			exec_pipe(&(*node)->left, env);
		}
		dup2(fd[0], STDIN_FILENO);
		waitpid(child, NULL, 0);
	}
}
