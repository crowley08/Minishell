/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:53:32 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 13:09:27 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*new_env(void)
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

void	free_env(t_env *env)
{
	if (env->name)
		free(env->name);
	if (env->value)
		free(env->value);
	free(env);
}

void	free_env_list(t_env **list)
{
	t_env	*env;

	while (list && *list)
	{
		env = *list;
		*list = (*list)->next;
		free_env(env);
	}
}
