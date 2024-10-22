/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:35 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	print_exit_error(int status)
{
	ft_putstr_fd("msh: exit: too many arguments\n", 2);
	return (status);
}

int	ms_exit(t_msh *msh, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (cmd->arg_list)
	{
		if (cmd->arg_list->next)
			return (print_exit_error(-127));
		else
			status = ms_atoi(cmd->arg_list->value);
	}
	free_msh(msh, TRUE);
	exit(status);
}
