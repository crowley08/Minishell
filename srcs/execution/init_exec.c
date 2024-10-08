/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:25:23 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 15:56:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_path(char *cmd, t_env *envp)
{
	t_env *env_path;
	int i;
	char **paths;
	char *path;

	env_path = get_env("PATH", envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path->value, ':');
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path = heredoc_strjoin(path, cmd);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			break;
		free(path);
		path = NULL;
	}
	ft_free_tab_str(paths);
	return (path);
}

void exec_one_prompt(t_prompt *prompt, t_env *envp)
{
	char *path;
	char **arg;
	char **env;

	if (!(prompt->cmd))
		return;
	path = get_path(prompt->cmd->cmd, envp);
	if (path)
	{
		//! FIXME: leak memory
		arg = set_arg_execve(prompt);
		env = set_env_execve(envp);
		ft_printf("Path for %s: %s\n", prompt->cmd->cmd, path);
		if (execve("arg", arg, env) == -1)
		{
			ft_printf("Failed to exec\n");
			ft_free_tab_str(arg);
			ft_free_tab_str(env);
			free(path);
		}
	}
	else
		ft_printf("Path not found for %s\n", prompt->cmd->cmd);
}

void exec_list_prompt(t_prompt *list, t_env *envp)
{
	while (list)
	{
		exec_one_prompt(list, envp);
		list = list->next;
	}
}
