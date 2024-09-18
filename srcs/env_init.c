/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:13:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 11:00:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*env_free_list(t_env *list_env)
{
	t_env	*curr;

	while (list_env)
	{
		curr = list_env->next;
		env_free(list_env);
		list_env = curr;
	}
	return (NULL);
}
void	*env_free(t_env *env)
{
	if (env->name)
		free(env->name);
	if (env->value)
		free(env->value);
	free(env);
	return (NULL);
}

t_env	*envp_dup(char **envp)
{
	t_env	*new_env;
	int		i;
	t_env	*list_env;

	i = 0;
	if (!envp[i])
		return (NULL);
	list_env = env_create(envp[i++], '=');
	while (envp[i])
	{
		new_env = env_create(envp[i++], '=');
		if (!new_env)
			return (env_free_list(list_env));
		env_add(list_env, new_env);
	}
	return (list_env);
}
