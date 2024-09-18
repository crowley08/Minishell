/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:27:33 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 10:57:11 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*env_init(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->name = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_env	*env_create(char *str, char sep)
{
	t_env	*env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = env_init();
	while (str[i] && str[i] != sep)
		i++;
	env->name = ft_substr(str, j, i);
	if (str[i] != sep)
		return (env_free(env));
	j = i + 1;
	env->value = ft_substr(str, j, ft_strlen(str + j));
	return (env);
}

void	env_add(t_env *list_env, t_env *new_env)
{
	t_env	*last_env;
	t_env	*env;

	if (!list_env)
		return ;
	env = list_env;
	while (env)
	{
		last_env = env;
		if (ft_strncmp(env->name, new_env->name, strlen(new_env->name)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(new_env->value);
			env_free(new_env);
			return ;
		}
		env = env->next;
	}
	last_env->next = new_env;
}

t_env	*env_get(t_env *list_env, char *name)
{
	t_env	*env;

	if (!list_env)
		return (NULL);
	env = list_env;
	while (env)
	{
		if (ft_strncmp(env->name, name, strlen(name)) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	env_del(t_env *list_env, char *name)
{
	t_env	*before_env;
	t_env	*env;

	if (!list_env)
		return ;
	env = list_env;
	before_env = env;
	while (env)
	{
		if (ft_strncmp(env->name, name, strlen(name)) == 0)
		{
			before_env->next = env->next;
			env_free(env);
			return ;
		}
		before_env = env;
		env = env->next;
	}
	return ;
}
