/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:58 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 13:54:57 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_oldpwd(t_msh *msh)
{
	t_env	*env;
	char	*pwd;
	char	*oldpwd;

	env = msh->env_list;
	pwd = NULL;
	oldpwd = NULL;
	while (env && ft_strcmp(env->name, "PWD") != 0)
		env = env->next;
	pwd = ft_strdup(env->value);
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	if (!pwd || !oldpwd)
		return ;
	export(oldpwd, &msh->env_list, 0);
	free(oldpwd);
	free(pwd);
}

static void	update_pwd(t_msh *msh, char *path)
{
	char	cwd[PATH_MAX];
	char	*pwd;

	update_oldpwd(msh);
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror(path);
		return ;
	}
	pwd = ft_strjoin("PWD=", cwd);
	if (!pwd)
		return ;
	export(pwd, &msh->env_list, 0);
	free(pwd);
}

static int	no_directory(char *path)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": no such file or directory\n", 2);
	free(path);
	return (-127);
}

int	ms_cd(t_msh *msh, t_cmd *cmd)
{
	t_arg	*arg;
	int		status;
	char	*path;

	arg = cmd->arg_list;
	status = 1;
	if (arg && arg->next)
	{
		ft_putstr_fd("msh: cd: too many arguments", 2);
		return (status);
	}
	path = get_path(arg, msh);
	status = chdir(path);
	if (status == 0)
		update_pwd(msh, path);
	else if (status == -1)
		return (no_directory(path));
	else
		perror(path);
	free(path);
	return (status);
}
