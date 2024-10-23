/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:29:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/23 14:28:28 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_stx(t_error_state error)
{
	if (error == STX_PIPE)
		ft_putstr_fd("msh: syntax error near unexpected token `|'.\n",
			STDERR_FILENO);
	else if (error == STX_QUOTE)
		ft_putstr_fd("msh: syntax error near unmatched quote \" or '.\n",
			STDERR_FILENO);
	else if (error == STX_REDIR)
		ft_putstr_fd("msh: syntax error near unexpected token 'newline'.\n",
			STDERR_FILENO);
}

void	set_exit_status_msh_stx(t_msh *msh, t_error_state exit_status,
		t_bool *has_err)
{
	*has_err = FALSE;
	if (WIFEXITED(exit_status))
	{
		if (WEXITSTATUS(exit_status) != NOTHING)
		{
			*has_err = TRUE;
			msh->exit_status = 2;
		}
	}
	else if (WIFSIGNALED(exit_status))
	{
		*has_err = TRUE;
		msh->exit_status = WTERMSIG(exit_status);
	}
}
