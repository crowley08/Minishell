/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:11:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:29:19 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_heredoc(t_heredoc *heredoc)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->tmp_file)
	{
		unlink(heredoc->tmp_file);
		free(heredoc->tmp_file);
	}
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

void	free_heredoc_keep_file(t_heredoc *heredoc)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->tmp_file)
		free(heredoc->tmp_file);
	free(heredoc);
}

void	free_heredoc_list_keep_file(t_heredoc **list)
{
	t_heredoc	*heredoc;

	while (list && *list)
	{
		heredoc = *list;
		*list = (*list)->next;
		free_heredoc_keep_file(heredoc);
	}
	*list = NULL;
}
