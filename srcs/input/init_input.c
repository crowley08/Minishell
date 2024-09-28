/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:07:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 16:16:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool is_input_valid(char *line)
{
	t_error_stt error;

	error = NOTHING;
	if (is_empty_line(line))
		return (FALSE);
	// add_history(line);
	if (has_syntax_error(line, &error))
	{
		ft_printf("\e[31mSyntax Error %d : Invalid line\n\e[0m", error);
		return (FALSE);
	}
	return (TRUE);
}

char *get_input(void)
{
	char *line;
	char *input;

	while (42)
	{
		// line = readline("\e[33mMinishell$ \e[0m");
		line = ft_strdup("<<eof$HOME<<eof\" $USER 'araokotom' 1 \"<<eof_ cat");
		if (!is_input_valid(line))
		{
			free(line);
			continue;
		}
		ft_printf("\e[32mSyntax valid: \e[0m%s\n", line);
		input = trim_space_all(line);
		free(line);
		if (!input)
			continue;
		break;
	}
	return (input);
}
