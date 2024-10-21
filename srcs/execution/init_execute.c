/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:00:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 15:28:26 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void exit_err_pipe(t_msh *msh)
{
	perror("msh: pipe :");
	free_msh(msh, TRUE);
	exit(EXIT_FAILURE);
}

t_bool print_err_redir(t_bool val)
{
	perror("msh: redir: ");
	return (val);
}

void execute_msh(t_msh *msh)
{
	t_prompt *prompt_list;

	prompt_list = msh->prompt_list;
	if (prompt_list->next)
		// todo: create one child proc and execute in all prompts on child proc even if it's a builtins cmd
		execute_list_prompt(msh, prompt_list);
	else
		// todo:execute prompt on main proc if it's a builtins cmd,if not execute it on child proc
		execute_one_prompt(msh, prompt_list);
	free_msh_reset(msh, TRUE);
}
