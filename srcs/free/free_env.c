/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:12:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:19:31 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	t_env *env;

	while (list && *list)
	{
		env = *list;
		*list = (*list)->next;
		free_env(env);
	}
	*list = NULL;
}
