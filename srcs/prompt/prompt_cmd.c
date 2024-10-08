/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:44:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 14:10:03 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool prompt_create_cmd(t_prompt *prompt, char *value)
{
	t_cmd *cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (FALSE);
	cmd->cmd = value;
	cmd->args = NULL;
	prompt->cmd = cmd;
	return (TRUE);
}

t_bool prompt_add_cmd_arg(t_prompt *prompt, char *arg)
{
	t_arg *new_arg;
	t_arg *last_arg;

	if (!prompt || !prompt->cmd)
		return (FALSE);
	new_arg = (t_arg *)malloc(sizeof(t_arg));
	if (!new_arg)
		return (FALSE);
	new_arg->value = arg;
	new_arg->next = NULL;
	if (prompt->cmd->args)
	{
		last_arg = prompt->cmd->args;
		while (last_arg->next)
			last_arg = last_arg->next;
		last_arg->next = new_arg;
	}
	else
		prompt->cmd->args = new_arg;
	return (TRUE);
}