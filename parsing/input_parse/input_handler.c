/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:44:08 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:16:23 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	set_syntax_error(t_error_stat *curr_error, t_error_stat error)
{
	*curr_error = error;
	return (T);
}

char	*get_input(void)
{
	char	*line;
	char	*input;

	while (42)
	{
		ms_signal();
		line = readline("\033[1;91m$>\033[0m ");
		if (!line || !is_input_valid(line))
		{
			free(line);
			continue ;
		}
		input = trim_space_all(line);
		free(line);
		if (!input)
			continue ;
		break ;
	}
	return (input);
}
