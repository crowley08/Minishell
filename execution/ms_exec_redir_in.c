/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:12 by saandria          #+#    #+#             */
/*   Updated: 2024/10/15 17:37:43 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ms_redir_in(t_node *node)
{
	char	*file;

	file = NULL;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
		file = ft_strdup(node->right->left->cmd[0]);
	else
		file = ft_strdup(node->right->cmd[0]);
	return (file);
}

void	exec_redirin(t_node *node, t_msh *msh)
{
	int		fd;
	char	*file;

	file = ms_redir_in(node);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	free(file);
	ms_exec(node->left, msh);
}
