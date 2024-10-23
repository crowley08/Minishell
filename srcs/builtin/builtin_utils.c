/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:28:11 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 11:11:52 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmd_is_echo(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->value, "echo", 5) && cmd->arg_list
		&& !ft_strncmp(cmd->arg_list->value, "-n", 3))
		return (1);
	return (0);
}

static int	print_exit(char *s, t_bool *num)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("msh: exit: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	free(s);
	*num = TRUE;
	return (2);
}

int	ms_atoi(char *nptr, t_bool *num)
{
	int		sign;
	long	nbr;
	char	*s;

	nbr = 0;
	sign = 1;
	s = ft_strdup(nptr);
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			return (print_exit(s, num));
		nbr = nbr * 10 + *nptr - 48;
		nptr++;
	}
	free(s);
	return (nbr * sign);
}

int	cmd_is_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->value, "exit", 5)
		|| !ft_strncmp(cmd->value, "cd", 3)
		|| !ft_strncmp(cmd->value, "pwd", 4)
		|| !ft_strncmp(cmd->value, "env", 4)
		|| !ft_strncmp(cmd->value, "export", 7)
		|| !ft_strncmp(cmd->value, "unset", 6)
		|| cmd_is_echo(cmd))
		return (1);
	return (0);
}
