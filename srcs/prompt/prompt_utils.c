/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:15 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 16:30:29 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void print_prompts(t_prompt *prompt)
{
	int i;

	i = 0;
	if (prompt)
	{
		ft_printf("PROMPTS:\n");
		while (prompt)
		{
			ft_printf("PROMPT %d:\n", ++i);
			print_prompt_cmd(prompt->cmd);
			print_prompt_redir_in(prompt->redir_in);
			print_prompt_redir_out(prompt->redir_out);
			prompt = prompt->next;
		}
	}
}

t_token_type get_token_type(char *value)
{
	if ((ft_strncmp(value, ">", ft_strlen(value)) == 0) || (ft_strncmp(value, ">>", ft_strlen(value)) == 0))
		return (REDIR_OUT);
	if (ft_strncmp(value, "<", ft_strlen(value)) == 0)
		return (REDIR_IN);
	return (WORD);
}

void print_arg(t_arg *arg)
{
	if (arg)
	{
		ft_printf("\t\tARG:\n", arg);
		while (arg)
		{
			ft_printf("\t\t\t$%s$\n", arg->value);
			arg = arg->next;
		}
	}
}
void print_prompt_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		ft_printf("\tCMD: $%s$\n", cmd->cmd);
		print_arg(cmd->args);
	}
}

void print_prompt_redir_in(t_redir_in *redir_in)
{
	if (redir_in)
	{
		ft_printf("\tREDIR IN: <\n");
		while (redir_in)
		{
			ft_printf("\t\t\t$%s$\n", redir_in->file);
			redir_in = redir_in->next;
		}
	}
}

void print_prompt_redir_out(t_redir_out *redir_out)
{
	if (redir_out)
	{
		ft_printf("\tREDIR OUT: >\n");
		while (redir_out)
		{
			ft_printf("\t\t\t$%s$ \t$%d$\n", redir_out->file, redir_out->type);
			redir_out = redir_out->next;
		}
	}
}
