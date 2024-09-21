/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:58:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 00:50:36 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_data(t_data *data)
{
	if (data->envp)
		free_list_env(&(data->envp));
	if (data->prompt)
		free(data->prompt);
}

void	free_env(t_env *env)
{
	free(env->name);
	free(env->value);
	free(env);
}

void	free_list_env(t_env **list)
{
	t_env	*env;

	while (list && *list)
	{
		env = *list;
		*list = (*list)->next;
		free_env(env);
	}
}
