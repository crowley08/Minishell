/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:01:27 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 13:40:41 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ms_getenv(char *name, t_env *env)
{
	char	*value;
	t_env	*cur;

	value = NULL;
	cur = env;
	while (cur)
	{
		if (ft_strcmp(name, cur->name) == 0)
			value = ft_strdup(cur->value);
		cur = cur->next;
	}
	return (value);
}

char	*get_path(t_arg *arg_list, t_msh *msh)
{
	char	*path;
	t_arg	*arg;
	t_env	*env;

	arg = arg_list;
	path = NULL;
	env = msh->env_list;
	if (arg == NULL || ft_strcmp(arg->value, "~") == 0)
		path = ms_getenv("HOME", env);
	else if (ft_strcmp(arg->value, "-") == 0)
		path = ms_getenv("OLDPWD", env);
	else
		path = ft_strdup(arg->value);
	return (path);
}
