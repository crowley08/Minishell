/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:07:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/10 12:55:46 by arakotom         ###   ########.fr       */
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
		// line = ft_strdup("<file_in.txt cat Makefile>file_out.txt|echo \" bonjour $USER\">> file1|cd director|< file2 echo 'bonjour \"$USER\"'|< NO_CMD");
		line = ft_strdup("cat Makefile | grep : | wc");
		if (!line || !is_input_valid(line))
		{
			free(line);
			continue;
		}
		// ft_printf("\e[32mSyntax valid: \e[0m%s\n", line);
		input = trim_space_all(line);
		free(line);
		if (!input)
			continue;
		break;
	}
	return (input);
}

char *parse_input_var(char *input, t_env *envp)
{
	char *new_input;
	t_heredoc *heredoc;

	heredoc = get_all_heredoc(input);
	if (heredoc)
	{
		if (!create_file_heredoc(heredoc, envp))
		{
			ft_printf("Error, heredoc failed\n");
			free(input);
			free(heredoc);
			return (NULL);
		}
		input = get_new_input_heredoc(input, heredoc, TRUE);
		free_heredoc_list(&heredoc);
	}
	new_input = get_new_input_expander(input, envp, TRUE);
	if (!new_input)
	{
		ft_printf("Error, parsing failed");
		free(input);
		return (NULL);
	}
	return (new_input);
}
