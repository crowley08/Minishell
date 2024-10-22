/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:49 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 14:05:39 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_echo(t_cmd *cmd)
{
	if (cmd_is_echo(cmd))
	{
		cmd->arg_list = cmd->arg_list->next;
		while (cmd->arg_list)
		{
			ft_putstr_fd(cmd->arg_list->value, STDOUT_FILENO);
			cmd->arg_list = cmd->arg_list->next;
		}
	}
	return (0);
}
