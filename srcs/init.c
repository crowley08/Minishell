/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:00:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 14:21:42 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	data_init(t_data *data, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	data->envp = NULL;
	data->prompt = NULL;
}

t_env	*env_new(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->name = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_bool	envp_dup(t_data *data, char **envp)
{
	t_env	*list;
	t_env	*env;
	int		i;

	if (!(*envp))
		return (FALSE);
	i = 0;
	list = NULL;
	while (envp[i])
	{
		env = env_create(envp[i]);
		if (env)
			env_add(&list, env);
		i++;
	}
	if (!list)
		return (FALSE);
	data->envp = list;
	return (TRUE);
}
