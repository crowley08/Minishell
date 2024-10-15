/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_redir_in_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:13:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 10:32:03 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

t_bool	prompt_add_redir_in(t_prompt *prompt, char *file)
{
	t_redir_in	*last_redir;
	t_redir_in	*new_redir;

	if (!prompt)
		return (FALSE);
	new_redir = prompt_create_redir_in(file);
	if (!new_redir)
		return (FALSE);
	if (prompt->redir_in_list)
	{
		last_redir = prompt->redir_in_list;
		while (last_redir->next)
			last_redir = last_redir->next;
		last_redir->next = new_redir;
	}
	else
		prompt->redir_in_list = new_redir;
	return (TRUE);
}
