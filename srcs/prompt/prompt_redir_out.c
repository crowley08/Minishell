/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_redir_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:37:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 15:00:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir_out *prompt_create_redir_out(char *file, t_rd_out_type type)
{
	t_redir_out *redir;

	redir = (t_redir_out *)malloc(sizeof(t_redir_out));
	if (!redir)
		return (NULL);
	redir->file = file;
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

t_bool prompt_add_file_redir_out(t_prompt *prompt, char *file, t_rd_out_type type)
{
	t_redir_out *last_file;
	t_redir_out *new_file;

	if (!prompt)
		return (FALSE);
	new_file = prompt_create_redir_out(file, type);
	if (!new_file)
		return (FALSE);
	if (prompt->redir_out)
	{
		last_file = prompt->redir_out;
		while (last_file->next)
			last_file = last_file->next;
		last_file->next = new_file;
	}
	else
		prompt->redir_out = new_file;
	return (TRUE);
}
