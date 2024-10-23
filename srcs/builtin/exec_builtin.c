/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:38:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 13:25:42 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_exec_builtin(t_msh *msh, t_cmd *cmd)
{
	if (!set_all_redir_ok(msh->prompt_list))
	{
		free_msh_keep_file(msh, TRUE);
		return (EXIT_FAILURE);
	}
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
	if (!ft_strncmp(cmd->value, "export", 7))
		return (ms_export(msh, cmd));
	if (!ft_strncmp(cmd->value, "cd", 3))
		return (ms_cd(msh, cmd));
	return (0);
}
