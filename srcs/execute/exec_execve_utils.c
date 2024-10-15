/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execve_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:44:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:17:32 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	arg_list_len(t_arg *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

int	env_list_len(t_env *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void	reset_std_in_out(int *std_in, int *std_out)
{
	dup2(*std_in, STDIN_FILENO);
	dup2(*std_out, STDOUT_FILENO);
	close(*std_in);
	close(*std_out);
}
