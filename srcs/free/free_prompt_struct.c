/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:20:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 08:42:55 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_cmd(t_cmd *cmd)
{
	if (cmd->value)
		free(cmd->value);
	if (cmd->arg_list)
		free_arg_list(&(cmd->arg_list));
	free(cmd);
}

void free_redir_in_list(t_redir_in **list)
{
	t_redir_in *redir;

	while (list && *list)
	{
		redir = *list;
		*list = (*list)->next;
		free_redir_in(redir);
	}
	*list = NULL;
}

void free_redir_out_list(t_redir_out **list)
{
	t_redir_out *redir;

	while (list && *list)
	{
		redir = *list;
		*list = (*list)->next;
		free_redir_out(redir);
	}
	*list = NULL;
}

void free_prompt_list(t_prompt **list)
{
	t_prompt *prompt;

	while (list && *list)
	{
		prompt = *list;
		*list = (*list)->next;
		free_prompt(prompt);
	}
	*list = NULL;
}
