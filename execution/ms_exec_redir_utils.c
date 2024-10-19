/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:33:47 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:09:02 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_if_fd_invalid(t_msh *msh, char *file)
{
	free_spl(msh->envc);
	free(file);
	free_node(&msh->node);
	free_all(msh);
	perror("open");
	exit (EXIT_FAILURE);
}
