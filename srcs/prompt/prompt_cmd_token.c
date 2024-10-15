/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_cmd_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:10:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:44:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	prompt_create_cmd(t_prompt *prompt, char *value)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (FALSE);
	cmd->value = value;
	cmd->arg_list = NULL;
	prompt->cmd = cmd;
	return (TRUE);
}

t_bool	prompt_add_cmd_arg(t_prompt *prompt, char *arg)
{
	t_arg	*new_arg;
	t_arg	*last_arg;

	if (!prompt || !prompt->cmd)
		return (FALSE);
	new_arg = (t_arg *)malloc(sizeof(t_arg));
	if (!new_arg)
		return (FALSE);
	new_arg->value = arg;
	new_arg->next = NULL;
	if (prompt->cmd->arg_list)
	{
		last_arg = prompt->cmd->arg_list;
		while (last_arg->next)
			last_arg = last_arg->next;
		last_arg->next = new_arg;
	}
	else
		prompt->cmd->arg_list = new_arg;
	return (TRUE);
}
