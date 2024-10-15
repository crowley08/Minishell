/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_redir_out_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:36:37 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 11:36:31 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir_out	*prompt_create_redir_out(char *file, t_redir_out_type type)
{
	t_redir_out	*redir;

	redir = (t_redir_out *)malloc(sizeof(t_redir_out));
	if (!redir)
		return (NULL);
	redir->file = file;
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

t_bool	prompt_add_redir_out(t_prompt *prompt, char *file,
		t_redir_out_type type)
{
	t_redir_out	*last_redir;
	t_redir_out	*new_redir;

	if (!prompt)
		return (FALSE);
	new_redir = prompt_create_redir_out(file, type);
	if (!new_redir)
		return (FALSE);
	if (prompt->redir_out_list)
	{
		last_redir = prompt->redir_out_list;
		while (last_redir->next)
			last_redir = last_redir->next;
		last_redir->next = new_redir;
	}
	else
		prompt->redir_out_list = new_redir;
	return (TRUE);
}
