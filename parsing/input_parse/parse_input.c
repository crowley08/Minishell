/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:41:38 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:29:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	complete_eof_name(char *eof_line, int *start, int *end, char **eof)
{
	int		len;
	char	*name;

	len = *end - *start;
	if (eof_line[*start] && len > 0 && (!is_quote(eof_line[*start])
			|| !is_quote(eof_line[*start + 1])))
	{
		name = ft_substr(eof_line, *start, len);
		*eof = heredoc_strjoin(*eof, name);
		free(name);
		*start = *end;
	}
	if (is_quote(eof_line[*end]))
	{
		*start = *end + 1;
		if (is_quote(eof_line[*start]))
			(*start)++;
	}
	*end = *start;
}

t_bool	is_empty_line(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_env	*get_env_name(char *name, t_env *list)
{
	if (!name)
		return (NULL);
	while (list)
	{
		if (ft_strncmp(list->name, name, ft_strlen(name)) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

char	*parse_input_var(char *input, t_env *envp)
{
	char		*new_input;
	t_heredoc	*heredoc;

	heredoc = get_all_heredoc(input);
	if (heredoc)
	{
		if (!create_file_heredoc(heredoc, envp))
		{
			printf("Error, heredoc failed\n");
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
		printf("Error, parsing failed");
		free(input);
		return (NULL);
	}
	return (new_input);
}
