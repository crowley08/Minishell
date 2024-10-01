/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:49:01 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 22:55:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*get_env(char *name, t_env *list)
{
	if (!name)
		return (NULL);
	while (list)
	{
		if (ft_strncmp(list->name, name, ft_strlen(name)) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_env	*create_env(char *str)
{
	t_env	*env;
	char	*char_equal;

	env = new_env();
	if (!env || !str || !(*str))
		return (NULL);
	char_equal = ft_strchr(str, '=');
	if (!char_equal || (char_equal - str) == 0)
		return (NULL);
	env->name = ft_substr(str, 0, (char_equal - str));
	env->value = ft_strdup(char_equal + 1);
	return (env);
}

void	add_env_list(t_env **list, t_env *env)
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

t_bool	dup_envp(t_data *data, char **envp)
{
	t_env	*list;
	t_env	*env;

	if (!(*envp))
		return (FALSE);
	list = NULL;
	while (envp && *envp)
	{
		env = create_env(*envp);
		if (env)
			add_env_list(&list, env);
		envp++;
	}
	if (!list)
		return (FALSE);
	data->envp = list;
	return (TRUE);
}
