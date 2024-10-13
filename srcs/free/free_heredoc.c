/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:03:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 18:08:39 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
