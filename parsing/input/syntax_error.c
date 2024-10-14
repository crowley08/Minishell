/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:52:45 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:53:14 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_syntax(t_msh *msh, char *input)
{
	perror("msh: syntax error");
	free(input);
	free_msh_reset(msh);
}

t_bool	set_syntax_error(t_error *error, t_error type)
{
	*error = type;
	return (T);
}

t_bool	has_syntax_error(t_msh *msh, char *input)
{
	int		status_syntax;
	t_bool	has_error;
	pid_t	pid_syntax;

	pid_syntax = fork();
	if (pid_syntax < 0)
		error_fork_syntax(msh, input);
	else if (pid_syntax == 0)
		exit(launch_syntax_validation_proc(msh, input));
	waitpid(pid_syntax, &status_syntax, 0);
	has_error = F;
	set_exit_status_syntax(msh, status_syntax, &has_error);
	if (has_error)
		error_syntax(msh, input);
	return (has_error);
}
