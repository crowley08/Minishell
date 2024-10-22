/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:52:27 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 13:48:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	print_error_env(int status, char *args)
{
	ft_putstr_fd("env: ", STDERR_FILENO);
	ft_putstr_fd(args, STDERR_FILENO);
	ft_putstr_fd(": no such file or directory\n", STDERR_FILENO);
	return (status);	
}

static void	print_env_list(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
}

int	ms_env(t_msh *msh, t_cmd *cmd)
{
	if (cmd->arg_list)
		return (print_error_env(127, cmd->arg_list->value));
	print_env_list(msh->env_list);
	return (0);
}
