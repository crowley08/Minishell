/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_out_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:33:47 by saandria          #+#    #+#             */
/*   Updated: 2024/10/15 16:04:57 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_rout_or_append(int type)
{
	if (type == REDIR_OUT_NODE || type == APPEND_NODE)
		return (1);
	return (0);
}

void	free_if_fd_invalid(t_msh *msh, char *file, char *path)
{
	free(path);
	free_spl(msh->envc);
	free(file);
	free_node(&msh->node);
	free_all(msh);
	perror("open");
	exit (EXIT_FAILURE);
}
