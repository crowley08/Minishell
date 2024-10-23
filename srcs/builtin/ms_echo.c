/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:49 by saandria          #+#    #+#             */
/*   Updated: 2024/10/23 16:10:35 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_with_no_option(t_arg *args)
{
	while (args)
	{
		ft_putendl_fd(args->value, STDOUT_FILENO);
		args = args->next;
	}
}

static void	print_with_n_option(t_arg *args)
{
	while (args)
	{
		ft_putstr_fd(args->value, STDOUT_FILENO);
		args = args->next;
	}
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
	if (ft_strncmp(args->value, "-n", 2) == 0)
	{
		args = args->next;
		print_with_n_option(args);
	}
	else
		print_with_no_option(args);
	return (0);
}
