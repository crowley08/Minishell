/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:50:14 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 15:35:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_input(t_msh *msh)
{
	char	*line;
	char	*input;

	while (42)
	{
		set_signal_handler();
		line = readline("\e[33mminishell$ \e[0m");
		if (line == NULL)
			exit_msh_sigeof(msh);
		if (is_empty_line(line))
			continue ;
		add_history(line);
		input = trim_sp_all(line);
		free(line);
		if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
			exit_msh_exit(msh, input);
		break ;
	}
	return (input);
}

void	set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error)
{
	*has_error = FALSE;
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
}

int	launch_syntax_validation_proc(t_msh *msh, char *input)
{
	int	exit_status;

	exit_status = launch_syntax_validation(input);
	free_msh_syntax(msh, input);
	return (exit_status);
}

t_bool	has_syntax_error(t_msh *msh, char *input)
{
	pid_t	pid_syntax;
	int		status_syntax;
	t_bool	has_error;

	pid_syntax = fork();
	if (pid_syntax < 0)
		error_fork_syntax(msh, input);
	else if (pid_syntax == 0)
		exit(launch_syntax_validation_proc(msh, input));
	waitpid(pid_syntax, &status_syntax, 0);
	set_exit_status_syntax(msh, status_syntax, &has_error);
	if (has_error)
		error_syntax(msh, input);
	return (has_error);
}
