/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:28:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:26:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	get_input_line_ok(t_msh *msh)
{
	char	*line;

	while (42)
	{
		set_signal_handler();
		line = readline("\e[33mminishell$ \e[0m");
		if (line == NULL)
			exit_msh_eof(msh);
		if (is_empty_str(line))
			continue ;
		add_history(line);
		break ;
	}
	msh->input = trim_space_all(line);
	free(line);
	if (!(msh->input))
		return (reset_msh_err_get_input_line(msh, FALSE));
	return (TRUE);
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

void	run_syntax_validation(t_msh *msh)
{
	t_error_state	error;

	error = check_syntax_validation(msh->input);
	free_msh(msh, TRUE);
	if (error == NOTHING)
		exit(EXIT_SUCCESS);
	print_err_stx(error);
	exit(error);
}

t_bool	syntax_input_ok(t_msh *msh)
{
	pid_t	pid_stx;
	int		exit_status_stx;
	t_bool	has_err;

	pid_stx = fork();
	if (pid_stx < 0)
		exit_err_fork(msh);
	else if (pid_stx == 0)
		run_syntax_validation(msh);
	waitpid(pid_stx, &exit_status_stx, 0);
	set_exit_status_msh_stx(msh, exit_status_stx, &has_err);
	if (has_err)
		return (free_msh_reset(msh, FALSE));
	return (TRUE);
}
