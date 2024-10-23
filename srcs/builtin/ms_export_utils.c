/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:34 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 11:10:02 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	name_is_valid(char *name)
{
	int	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 0;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	name_exists(char *name, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
		{
			unset(tmp->name, env);
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

t_env	*new_env_list(char *value)
{
	int		i;
	int		start;	
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	if (!ft_strchr(value, '='))
	{
		new->name = ft_strdup(value);
		new->value = NULL;
		new->next = NULL;
		return (new);
	}
	i = 0;
	start = i;
	while (value[i] != '=')
		i++;
	new->name = ft_substr(value, start, i - start);
	start = i + 1;
	while (value[i])
		i++;
	new->value = ft_substr(value, start, i - start);
	new->next = NULL;
	return (new);
}

static void	swap(t_env *node1, t_env *node2)
{
	char	*name;
	char	*value;

	name = node1->name;
	value = node1->value;
	node1->name = node2->name;
	node1->value = node2->value;
	node2->name = name;
	node2->value = value;
}

t_env	*sort_env(t_env **env)
{
	t_env	*sort;

	sort = *env;
	while (sort)
	{
		if (sort->next && ft_strcmp(sort->name, sort->next->name) > 0)
		{
			swap(sort, sort->next);
			sort = *env;
		}
		else
			sort = sort->next;
	}
	return (*env);
}
