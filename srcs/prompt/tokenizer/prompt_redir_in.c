/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_redir_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:21 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 10:35:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_redir_in	*prompt_create_redir_in(char *file)
{
	t_redir_in	*redir;

	redir = (t_redir_in *)malloc(sizeof(t_redir_in));
	if (!redir)
		return (NULL);
	redir->file = file;
	redir->next = NULL;
	return (redir);
}

t_bool	prompt_add_file_redir_in(t_prompt *prompt, char *file)
{
	t_redir_in	*last_file;
	t_redir_in	*new_file;

	if (!prompt)
		return (FALSE);
	new_file = prompt_create_redir_in(file);
	if (!new_file)
		return (FALSE);
	if (prompt->redir_in)
	{
		last_file = prompt->redir_in;
		while (last_file->next)
			last_file = last_file->next;
		last_file->next = new_file;
	}
	else
		prompt->redir_in = new_file;
	return (TRUE);
}
