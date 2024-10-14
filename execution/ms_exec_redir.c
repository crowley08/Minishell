/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:22:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 15:24:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_append(t_node *node, t_msh *msh)
{
	int		fd;
	int		i;
	mode_t	mode;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
		node->right = node->right->left;
	printf("%s\n", node->right->cmd[0]);
	fd = open(node->right->cmd[0], O_CREAT | O_RDWR | O_APPEND, mode);
	if (fd == -1)
	{
		free_spl(msh->envc);
		free_node(&msh->node);
		free_all(msh);
		perror("open");
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(node->left, msh);

}

void	exec_dir(t_node *node, t_msh *msh)
{
	int		fd;
	int		i;
	mode_t	mode;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
		node->right = node->right->left;
	printf("%s\n", node->right->cmd[0]);
	fd = open(node->right->cmd[0], O_CREAT | O_RDWR | O_TRUNC, mode);
	if (fd == -1)
	{
		free_spl(msh->envc);
		free_node(&msh->node);
		free_all(msh);
		perror("open");
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(node->left, msh);
}
