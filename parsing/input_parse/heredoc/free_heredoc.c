/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:22:40 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:31:26 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_heredoc(t_heredoc *heredoc)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->filename)
		free(heredoc->filename);
	free(heredoc);
}

void	free_heredoc_list(t_heredoc **list)
{
	t_heredoc	*heredoc;

	while (list && *list)
	{
		heredoc = *list;
		*list = (*list)->next;
		free_heredoc(heredoc);
	}
	*list = NULL;
}
