/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:27:03 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 17:25:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//! NOT DONE
void execute_prompt_child(t_prompt *prompt)
{
	// verification des redir in et out
	if (has_error_redir_exec(prompt))
		printf("ERROR: Redir IN OUT\n");
	// change les inputs et outputs si necessaire;
	else if (set_redir_std_in_out_error(prompt))
		printf("ERROR: set STDIN STDOUT\n");
	else
	{
	}
	// verification si builting
	// si non creation arg and envp dans un child proc
	// execute execve
}

t_bool execute_prompts_list(t_msh *msh)
{
	t_prompt *prompt_list;
}
