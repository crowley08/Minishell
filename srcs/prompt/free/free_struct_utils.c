/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:04:10 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 14:48:50 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void free_arg(t_arg *arg)
{
	if (arg->value)
		free(arg->value);
	free(arg);
}

void free_arg_list(t_arg **list)
{
	t_arg *arg;

	while (list && *list)
	{
		arg = *list;
		*list = (*list)->next;
		free_arg(arg);
	}
	*list = NULL;
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
