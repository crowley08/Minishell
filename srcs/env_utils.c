/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:08 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 13:19:23 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_env	*env_create(char *str)
{
	t_env	*env;
	char	*char_equal;

	env = env_new();
	if (!env)
		return (NULL);
	char_equal = ft_strchr(str, '=');
	if (!char_equal || (char_equal - str) == 0)
		return (NULL);
	env->name = ft_substr(str, 0, (char_equal - str));
	env->value = ft_strdup(char_equal + 1);
	return (env);
}

void	env_add(t_env **list, t_env *env)
{
	t_env	*last;

	if (!(*list))
		*list = env;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = env;
	}
}
