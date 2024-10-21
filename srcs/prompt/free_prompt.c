/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:19:54 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:22:13 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	free_arg(t_arg *arg, t_bool val)
{
	if (arg->value)
		free(arg->value);
	free(arg);
	return (val);
}

t_bool	free_arg_list(t_arg **list, t_bool val)
{
	t_arg	*arg;

	while (list && *list)
	{
		arg = *list;
		*list = (*list)->next;
		free_arg(arg, val);
	}
	*list = NULL;
	return (val);
}

t_bool	free_redir_in(t_redir_in *redir_in, t_bool val)
{
	if (redir_in->file)
		free(redir_in->file);
	free(redir_in);
	return (val);
}

t_bool	free_redir_out(t_redir_out *redir_out, t_bool val)
{
	if (redir_out->file)
		free(redir_out->file);
	free(redir_out);
	return (val);
}

t_bool	free_prompt(t_prompt *prompt, t_bool val)
{
	if (prompt->cmd)
		free_cmd(prompt->cmd, val);
	if (prompt->redir_in_list)
		free_redir_in_list(&(prompt->redir_in_list), val);
	if (prompt->redir_out_list)
		free_redir_out_list(&(prompt->redir_out_list), val);
	free(prompt);
	return (val);
}
