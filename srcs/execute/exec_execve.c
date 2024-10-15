/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:10:04 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*search_path(char *cmd_value, t_env *env_list)
{
	char	**paths;
	char	*path;
	t_env	*env_path;
	int		i;

	env_path = get_env("PATH", env_list);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path->value, ':');
	i = 0;
	path = NULL;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path = msh_strjoin(path, cmd_value);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_free_tab_str(paths);
	return (path);
}

char	**set_argv_execve(t_cmd *cmd)
{
	char	**argv;
	int		len;
	int		i;
	t_arg	*arg_list;

	len = 2;
	i = 1;
	len += arg_list_len(cmd->arg_list);
	argv = (char **)malloc(sizeof(char *) * len);
	argv[0] = ft_strdup(cmd->value);
	arg_list = cmd->arg_list;
	while (i < len - 1)
	{
		argv[i++] = ft_strdup(arg_list->value);
		arg_list = arg_list->next;
	}
	argv[len - 1] = NULL;
	return (argv);
}

char	**set_envp_execve(t_env *env_list)
{
	char	**envp;
	char	*env;
	int		len;
	int		i;

	len = 1;
	i = 0;
	len += env_list_len(env_list);
	envp = malloc(sizeof(char *) * len);
	while (i < len - 1)
	{
		env = ft_strjoin(env_list->name, "=");
		env = msh_strjoin(env, env_list->value);
		envp[i++] = env;
		env_list = env_list->next;
	}
	envp[len - 1] = NULL;
	return (envp);
}

int	exec_execve(t_msh *msh, t_cmd *cmd)
{
	char	*path;
	char	**argv;
	char	**envp;

	if (!cmd)
		return (EXIT_SUCCESS);
	path = search_path(cmd->value, msh->env_list);
	if (!path)
		return (EXIT_FAILURE);
	else
	{
		argv = set_argv_execve(cmd);
		envp = set_envp_execve(msh->env_list);
		free_msh_keep_file(msh);
		if (execve(path, argv, envp) != -1)
			return (EXIT_SUCCESS);
		ft_free_tab_str(argv);
		ft_free_tab_str(envp);
		free(path);
		return (EXECVE_FAILED);
	}
}
