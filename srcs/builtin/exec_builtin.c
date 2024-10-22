/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:38:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/22 15:35:19 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_exec_builtin(t_msh *msh, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->value, "env", 4))
		return (ms_env(msh, cmd));
	if (!ft_strncmp(cmd->value, "pwd", 4))
		return (ms_pwd());
	if (cmd_is_echo(cmd))
		return (ms_echo(cmd));
	if (!ft_strncmp(cmd->value, "exit", 5))
		return (ms_exit(msh, cmd));
	if (!ft_strncmp(cmd->value, "unset", 6))
		return (ms_unset(msh, cmd));
	return (0);
}
