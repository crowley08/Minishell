/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:49:33 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 22:50:16 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_ast(t_node **node)
{
	if (!*node)
		return ;
	printf("type : %d\n", (*node)->type);
	if ((*node)->cmd)
		printf("%s\n", (*node)->cmd[0]);
	print_ast(&(*node)->left);
	print_ast(&(*node)->right);
}
