/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:22:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:10:06 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_dir(t_node *node, t_msh *msh)
{
	int		fd;
	mode_t	mode;
	char	*file;
	int		flags;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->type == APPEND_NODE)
		flags = O_CREAT | O_RDWR | O_APPEND ;
	else
		flags = O_CREAT | O_RDWR | O_TRUNC ;
	file = ft_strdup(node->cmd[1]);
	fd = open(file, flags, mode);
	if (fd == -1)
		free_if_fd_invalid(msh, file);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	free(file);
	ms_exec(node->right, msh);
}
