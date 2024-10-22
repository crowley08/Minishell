/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:44:58 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 15:57:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_export(t_msh *msh, t_cmd *cmd)
{
	t_env	*print;

	print = msh->env_list;
	if (cmd->arg_list)
	{
		while (cmd->arg_list)
		{
		//	export(cmd->arg_list->value, msh->env_list);
			cmd->arg_list = cmd->arg_list->next;
		}
		return (0);
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
