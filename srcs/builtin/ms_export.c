/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:44:58 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 17:08:22 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*new_env_list(char *value)
{
	int		i;
	int		start;	
	t_env	*new;

	i = 0;
	start = i;
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
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

static int	name_is_valid(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

t_env	*export(char *arg, t_env **env, int *status)
{
	t_env	*new;

	new = new_env_list(arg);
	if (!name_is_valid(new->name))
	{
		ft_putstr_fd("msh: export: ", 2);
		ft_putstr_fd(new->name, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		free(new->name);
		if (new->value)
			free(new->value);
		free(new);
		*status = -127;
	}
	else if (name_is_valid(new->name))
	{
		if (new->value != NULL)
			add_env_list(env, new);
		else
		{
			free(new->name);
			if (new->value)
				free(new->value);
			free(new);
			return (*env);
		}
	}
	return (*env);
}

int	ms_export(t_msh *msh, t_cmd *cmd)
{
	t_env	*print;
	int		status;

	status = 0;
	print = msh->env_list;
	if (cmd->arg_list)
	{
		while (cmd->arg_list)
		{
			msh->env_list = export(cmd->arg_list->value, &msh->env_list, &status);
			cmd->arg_list = cmd->arg_list->next;
		}
		return (status);
	}
	else
	{
		while (print)
		{
			printf("export %s=%s\n", print->name, print->value);
			print = print->next;
		}
		return (0);
	}
	return (0);
}
