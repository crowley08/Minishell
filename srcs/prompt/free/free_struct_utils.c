/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:04:10 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 08:14:59 by arakotom         ###   ########.fr       */
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

void free_arg_rd_out(t_arg_rd_out *arg_rd_out)
{
	if (arg_rd_out->file)
		free(arg_rd_out->file);
	free(arg_rd_out);
}

void free_arg_rd_out_list(t_arg_rd_out **list)
{
	t_arg_rd_out *arg;

	while (list && *list)
	{
		arg = *list;
		*list = (*list)->next;
		free_arg_rd_out(arg);
	}
	*list = NULL;
}
