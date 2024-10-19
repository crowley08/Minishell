/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:12 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:10:38 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_redirin(t_node *node, t_msh *msh)
{
	int		fd;
	char	*file;

	file = ft_strdup(node->cmd[1]);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_if_fd_invalid(msh, file);
	dup2(fd, STDIN_FILENO);
	close(fd);
	free(file);
	ms_exec(node->right, msh);
}
