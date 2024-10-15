/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:28:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:37 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_dup_env(t_msh *msh)
{
	perror("msh: error, duplicate envp failed");
	free_msh(msh);
	exit(EXIT_FAILURE);
}

void	error_fork(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}

t_bool	set_error(t_error_stt *error, t_error_stt type)
{
	*error = type;
	return (TRUE);
}

void	print_syntax_error(t_error_stt error)
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

void	error_syntax_heredoc(t_msh *msh, char *input)
{
	free(input);
	free_msh_reset(msh);
}
