/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:21:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 14:49:39 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_cmd(t_cmd *cmd)
{
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->args)
		free_arg_list(&(cmd->args));
	free(cmd);
}

void	free_redir_in(t_redir_in *redir_in)
{
	if (redir_in->file)
		free(redir_in->file);
	free(redir_in);
}

void	free_redir_out(t_redir_out *redir_out)
{
	if (redir_out->file)
		free(redir_out->file);
	free(redir_out);
}

void	free_prompt(t_prompt *prompt)
{
	if (prompt->cmd)
		free_cmd(prompt->cmd);
	if (prompt->redir_in)
		free_redir_in_list(&(prompt->redir_in));
	if (prompt->redir_out)
		free_redir_out_list(&(prompt->redir_out));
	free(prompt);
}

void	free_prompt_list(t_prompt **list)
{
	t_prompt	*prompt;

	while (list && *list)
	{
		prompt = *list;
		*list = (*list)->next;
		free_prompt(prompt);
	}
	*list = NULL;
}
