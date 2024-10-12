/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:46:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 12:50:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			msh->exit_status = 2;
			*has_error = TRUE;
		}
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = WTERMSIG(status);
		*has_error = TRUE;
	}
	else
	{
		msh->exit_status = 1;
		*has_error = TRUE;
	}
}

t_bool has_syntax_error(t_msh *msh, char *input)
{
	int status_syntax;
	t_bool has_error;
	pid_t pid_syntax;

	pid_syntax = fork();
	if (pid_syntax < 0)
		ft_printf("Error: fork pid_syntax() returned %d\n", pid_syntax);
	else if (pid_syntax == 0)
	{
		free_msh_syntax(msh, input);
		// TODO: add child of validation input
		exit(EXIT_FAILURE);
	}
	waitpid(pid_syntax, &status_syntax, 0);
	has_error = FALSE;
	set_exit_status_syntax(msh, status_syntax, &has_error);
	return (has_error);
}
