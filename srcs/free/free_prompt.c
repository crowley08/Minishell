/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:19:54 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 08:40:07 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_arg(t_arg *arg)
{
	if (arg->value)
		free(arg->value);
	free(arg);
}

void	free_arg_list(t_arg **list)
{
	t_arg	*arg;

	while (list && *list)
	{
		arg = *list;
		*list = (*list)->next;
		free_arg(arg);
	}
	*list = NULL;
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
	if (prompt->redir_in_list)
		free_redir_in_list(&(prompt->redir_in_list));
	if (prompt->redir_out_list)
		free_redir_out_list(&(prompt->redir_out_list));
	free(prompt);
}
