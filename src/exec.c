/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/09/25 16:06:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_spl(char **env)
{
	int    i;

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
	i = -1;
	while (path[++i])
	    free(paths[i]);
	return (0);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	exec(t_token **token, char **env)
{
	char	**cmd;
	t_token	*t;
	int		i;
	char	*path;

	cmd = (char **)malloc(100000);
	t = *token;
	i = 0;
	while (t && t->type == 0)
	{
		cmd[i] = ft_strdup(t->value);
		printf("%s\n", cmd[i]);
		t = t->next;
		i++;
	}
	path = check_path(cmd[0], env);
	if (!path)
	{
		free_spl(cmd);
	    error();
	}
	if (execve(path, cmd, env) == -1)
		error();
}
