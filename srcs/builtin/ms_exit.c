/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 11:57:12 by saandria         ###   ########.fr       */
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
	t_bool	is_non_num;
	int		status;
	t_arg	*args;

	status = 0;
	is_non_num = FALSE;
	args = cmd->arg_list;
	if (args)
	{
		status = ms_atoi(args->value, &is_non_num);
		if (args->next && is_non_num == FALSE)
			return (print_exit_error(-127));
	}
	free_msh(msh, TRUE);
	exit(status);
}
