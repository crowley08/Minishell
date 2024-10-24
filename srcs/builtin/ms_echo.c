/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:49 by saandria          #+#    #+#             */
/*   Updated: 2024/10/24 13:50:06 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_with_no_option(t_arg *args)
{
	while (args)
	{
		if (args->value[0] == '$')
			ft_putstr_fd(args->value + 1, STDOUT_FILENO);
		else
			ft_putstr_fd(args->value, STDOUT_FILENO);
		args = args->next;
	}
	write(STDOUT_FILENO, "\n", 1);
}

static void	print_with_n_option(t_arg *args)
{
	while (args)
	{
		if (args->value[0] == '$')
			ft_putstr_fd(args->value + 1, STDOUT_FILENO);
		else
			ft_putstr_fd(args->value, STDOUT_FILENO);
		args = args->next;
	}
}

static int	check_option(t_arg *arg)
{
	int	i;

	i = 0;
	if (arg->value[i] == '-')
		i++;
	while (arg->value[i] == 'n')
		i++;
	if (!arg->value[i] && i > 1)
		return (1);
	return (0);
}

int	ms_echo(t_cmd *cmd)
{
	t_arg	*args;

	args = cmd->arg_list;
	if (!args || is_empty_str(args->value))
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	if (check_option(args) == 0)
	{
		print_with_no_option(args);
		return (0);
	}
	while (args && check_option(args))
		args = args->next;
	print_with_n_option(args);
	return (0);
}
