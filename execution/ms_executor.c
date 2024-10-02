/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/02 17:23:38 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_dir(t_node *node, char **env)
{
	int		fd;
	int		i;
	mode_t	mode;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	if (node->right->type == PIPE_NODE
		&& node->right->left->type == CMD_NODE)
		node->right = node->right->left;
	else if (node->right->type == PIPE_NODE
		&& node->right->left->type != CMD_NODE)
		node->right = node->right->right;
	while (node->right->cmd[i])
		i++;
	i--;
	printf("%s\n", node->right->cmd[i]);
	fd = open(node->right->cmd[i], O_CREAT | O_RDWR | O_TRUNC, mode);
	if (fd == -1)
		perror("open");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(node->left, env);
}

void	ms_exec(t_node *node, char **env)
{
	if (node->type == CMD_NODE)
		exec(node->cmd, env);
	else if (node->type == PIPE_NODE)
		exec_pipe(node, env);
	else if (node->type == REDIR_OUT_NODE)
		exec_dir(node, env);
}
