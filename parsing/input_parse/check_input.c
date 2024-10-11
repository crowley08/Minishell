/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:17 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:09:27 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	line_is_empty(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (F);
		str++;
	}
	return (T);
}

t_bool	has_syntax_error(char *line, t_error_stat *error)
{
	while (42)
	{
		if (has_quote_opened(line) && set_syntax_error(error, QUOTE))
			break ;
		if (has_pipe_start_end_redir(line) && set_syntax_error(error,
				PIPE_START_END))
			break ;
		if (has_dbl_pipe_succ(line) && set_syntax_error(error,
				PIPE_DBL_SUCC))
			break ;
		if (has_some_redir_invalid(line) && set_syntax_error(error, REDIR))
			break ;
		break ;
	}
	if (*error != NOTHING)
		return (T);
	return (F);
}

t_bool	is_input_valid(char *line)
{
	t_error_stat	error;

	error = NOTHING;
	if (line_is_empty(line))
		return (F);
	add_history(line);
	if (has_syntax_error(line, &error))
	{
		perror("\033[31mError");
		return (F);
	}
	return (T);
}
