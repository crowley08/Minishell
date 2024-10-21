/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:16:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 10:17:12 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void print_prompts(t_prompt *prompt)
{
	int i;
	i = 0;
	if (prompt)
	{
		printf("PROMPTS:\n");
		while (prompt)
		{
			printf("PROMPT %d:\n", ++i);
			print_prompt_cmd(prompt->cmd);
			print_prompt_redir_in(prompt->redir_in_list);
			print_prompt_redir_out(prompt->redir_out_list);
			prompt = prompt->next;
		}
	}
}
// ! FIXME: delete this function later
void print_arg(t_arg *arg)
{
	if (arg)
	{
		printf("\t\tARG:\n");
		while (arg)
		{
			printf("\t\t\t$%s$\n", arg->value);
			arg = arg->next;
		}
	}
}
// ! FIXME: delete this function later
void print_prompt_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		printf("\tCMD: $%s$\n", cmd->value);
		print_arg(cmd->arg_list);
	}
}
// ! FIXME: delete this function later
void print_prompt_redir_in(t_redir_in *redir_in)
{
	if (redir_in)
	{
		printf("\tREDIR IN: <\n");
		while (redir_in)
		{
			printf("\t\t\t$%s$\n", redir_in->file);
			redir_in = redir_in->next;
		}
	}
}
// ! FIXME: delete this function later
void print_prompt_redir_out(t_redir_out *redir_out)
{
	if (redir_out)
	{
		printf("\tREDIR OUT: >\n");
		while (redir_out)
		{
			printf("\t\t\t$%s$ \t$%d$\n", redir_out->file, redir_out->type);
			redir_out = redir_out->next;
		}
	}
}
