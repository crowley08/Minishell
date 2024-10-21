/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:00:32 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:21:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	free_heredoc(t_heredoc *heredoc, t_bool val)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->tmp_file)
	{
		unlink(heredoc->tmp_file);
		free(heredoc->tmp_file);
	}
	free(heredoc);
	return (val);
}

t_bool	free_heredoc_list(t_heredoc **list, t_bool val)
{
	t_heredoc	*heredoc;

	while (list && *list)
	{
		heredoc = *list;
		*list = (*list)->next;
		free_heredoc(heredoc, val);
	}
	*list = NULL;
	return (val);
}

t_bool	free_heredoc_keep_file(t_heredoc *heredoc, t_bool val)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->tmp_file)
		free(heredoc->tmp_file);
	free(heredoc);
	return (val);
}

t_bool	free_heredoc_list_keep_file(t_heredoc **list, t_bool val)
{
	t_heredoc	*heredoc;

	while (list && *list)
	{
		heredoc = *list;
		*list = (*list)->next;
		free_heredoc_keep_file(heredoc, val);
	}
	*list = NULL;
	return (val);
}
