/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:00:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/23 16:09:46 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_err_pipe(t_msh *msh)
{
	perror("msh: pipe :");
	free_msh(msh, TRUE);
	exit(EXIT_FAILURE);
}

t_bool	print_err_redir(t_bool val)
{
	perror("msh: redir: ");
	return (val);
}

void	execute_msh(t_msh *msh)
{
	t_prompt	*prompt_list;

	prompt_list = msh->prompt_list;
	if (prompt_list->next)
		execute_list_prompt(msh, prompt_list);
	else
		execute_one_prompt(msh, prompt_list);
	free_msh_reset(msh, TRUE);
}
