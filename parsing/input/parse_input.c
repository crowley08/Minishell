/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:31:24 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 13:32:54 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_msh_sigeof(t_msh *msh)
{
	free_msh(msh);
	printf("^D\n");
	exit(EXIT_SUCCESS);
}

char	*get_input(t_msh *msh)
{
	char	*line;
	char	*input;

	while (42)
	{
		ms_signal();
		line = readline("$> ");
		if (line == NULL)
			exit_msh_sigeof(msh);
		if (is_empty_line(line))
			continue ;
		add_history(line);
		input = trim_sp_all(line);
		free(line);
		if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
			exit_msh_exit(msh, input);
		printf("input trimmed: $%s$\n", input);
		break ;
	}
	return (input);
}

int	get_eof_len(char *input)
{
	int		len;
	t_quote	quote;

	len = 0;
	init_quote(&quote);
	while (input && input[len] && !is_redir(input[len])
		&& !ft_isspace(input[len]) && input[len] != '|')
	{
		update_quote(input[len], &quote);
		len++;
		while (quote_opened(quote))
		{
			update_quote(input[len], &quote);
			len++;
		}
	}
	return (len);
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
