/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:49 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 11:56:14 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_echo(t_cmd *cmd)
{
	t_arg	*args;

	args = cmd->arg_list;
	if (cmd_is_echo(cmd))
	{
		args = args->next;
		while (args)
		{
			ft_putstr_fd(args->value, STDOUT_FILENO);
			args = args->next;
		}
	}
	return (0);
}
