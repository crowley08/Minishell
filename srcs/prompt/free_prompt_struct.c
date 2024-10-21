/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:20:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 10:29:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool free_cmd(t_cmd *cmd, t_bool val)
{
	if (cmd->value)
		free(cmd->value);
	if (cmd->arg_list)
		free_arg_list(&(cmd->arg_list), val);
	free(cmd);
	return (val);
}

t_bool free_redir_in_list(t_redir_in **list, t_bool val)
{
	t_redir_in *redir;

	while (list && *list)
	{
		redir = *list;
		*list = (*list)->next;
		free_redir_in(redir, val);
	}
	*list = NULL;
	return (val);
}

t_bool free_redir_out_list(t_redir_out **list, t_bool val)
{
	t_redir_out *redir;

	while (list && *list)
	{
		redir = *list;
		*list = (*list)->next;
		free_redir_out(redir, val);
	}
	*list = NULL;
	return (val);
}

t_bool free_prompt_list(t_prompt **list, t_bool val)
{
	t_prompt *prompt;

	while (list && *list)
	{
		prompt = *list;
		*list = (*list)->next;
		free_prompt(prompt, val);
	}
	*list = NULL;
	return (val);
}
