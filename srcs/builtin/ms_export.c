/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:44:58 by saandria          #+#    #+#             */
/*   Updated: 2024/10/24 13:50:27 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*export(char *arg, t_env **env, int *status)
{
	t_env	*new;

	new = new_env_list(arg);
	if (!new)
		return (*env);
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
	else
	{
		if (name_exists(new->name, env))
			add_env_list(env, new);
	}
	return (*env);
}

static t_env	*dup_env(t_env *env)
{
	t_env	*dup;
	t_env	*new_dup;

	dup = NULL;
	new_dup = NULL;
	while (env)
	{
		new_dup = malloc(sizeof(t_env));
		new_dup->name = ft_strdup(env->name);
		new_dup->value = ft_strdup(env->value);
		new_dup->next = NULL;
		add_env_list(&dup, new_dup);
		env = env->next;
	}
	return (dup);
}

static void	print_export(t_env *print)
{
	while (print)
	{
		printf("export %s", print->name);
		if (print->value)
			printf("=\"%s\"", print->value);
		printf("\n");
		print = print->next;
	}
}

static void	free_envl(t_env **env)
{
	t_env	*current;
	t_env	*next;

	current = *env;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
	*env = NULL;
	free(current);
	current = NULL;
	next = NULL;
	return ;
}

int	ms_export(t_msh *msh, t_cmd *cmd)
{
	t_env	*print;
	int		s;
	t_arg	*args;

	s = 0;
	args = cmd->arg_list;
	if (args)
	{
		while (args)
		{
			export(args->value, &msh->env_list, &s);
			args = args->next;
		}
		return (s);
	}
	else
	{
		print = dup_env(msh->env_list);
		print = sort_env(&print);
		print_export(print);
		free_envl(&print);
		return (0);
	}
	return (0);
}
