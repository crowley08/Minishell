/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:08:57 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 15:05:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_msh_syntax(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
}

int	launch_syntax_validation_proc(t_msh *msh, char *input)
{
	int	exit_status;

	exit_status = launch_syntax_validation(input);
	free_msh_syntax(msh, input);
	free(msh);
	return (exit_status);
}

void	set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			msh->exit_status = 2;
			*has_error = T;
		}
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = WTERMSIG(status);
		*has_error = T;
	}
	else
	{
		msh->exit_status = 1;
		*has_error = T;
	}
}
