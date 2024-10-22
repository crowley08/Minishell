/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:19:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 15:33:58 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*unset(char *name, t_env **env)
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
	free(current->name);
	free(current->value);
	free(current);
	return (*env);
}

int	ms_unset(t_msh *msh, t_cmd *cmd)
{
	while (cmd->arg_list)
	{
		msh->env_list = unset(cmd->arg_list->value, &msh->env_list);
		cmd->arg_list = cmd->arg_list->next;
	}
	return (0);
}
