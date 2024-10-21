/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:07:03 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:46:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	reset_msh_err_get_input_line(t_msh *msh, t_bool val)
{
	ft_putstr_fd("msh: error getting input line\n", STDERR_FILENO);
	free_msh_reset(msh, val);
	return (val);
}

void	exit_err_fork(t_msh *msh)
{
	perror("msh: fork :");
	free_msh(msh, TRUE);
	exit(EXIT_FAILURE);
}
