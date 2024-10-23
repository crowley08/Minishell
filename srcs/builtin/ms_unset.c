/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:19:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 11:55:47 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*unset(char *name, t_env **env)
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	while (current && ft_strncmp(name, current->name, ft_strlen(name)))
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return (*env);
	prev->next = current->next;
	free_env(current, TRUE);
	return (*env);
}

int	ms_unset(t_msh *msh, t_cmd *cmd)
{
	t_arg	*args;

	args = cmd->arg_list;
	while (args)
	{
		unset(args->value, &msh->env_list);
		args = args->next;
	}
	return (0);
}
