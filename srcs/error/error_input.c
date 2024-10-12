/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:17:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 17:12:14 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool set_syntax_error(t_error_stt *error, t_error_stt type)
{
	*error = type;
	return (TRUE);
}

void print_syntax_error(t_error_stt error)
{
	if (error == STX_PIPE_START_END)
		perror("msh: syntax error near unexpected token `|'");
	else if (error == STX_QUOTE)
		perror("msh: syntax error near unclosed token \" or '");
	else if (error == STX_PIPE_SUCC)
		perror("msh: syntax error near unexpected token `||'");
	else if (error == STX_REDIR)
		perror("msh: syntax error near unexpected token `newline'");
}

void error_syntax(t_msh *msh, char *input)
{
	perror("msh: syntax error");
	free(input);
	//! FIXME: reset msh not free msh
	free_msh_reset(msh);
}
