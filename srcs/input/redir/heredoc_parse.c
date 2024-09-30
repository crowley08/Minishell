/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:18:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/30 15:51:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool	fill_file_input(int fd, t_heredoc heredoc)
{
	char	*input;

	while (42)
	{
		rl_on_new_line();
		input = readline("> ");
		if (!input || is_empty_line(input))
		{
			free(input);
			write(fd, "\n", 1);
			continue ;
		}
		else
		{
			if (ft_strncmp(input, heredoc.eof, ft_strlen(input)) == 0)
			{
				free(input);
				return (TRUE);
			}
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		free(input);
	}
}

t_bool	create_file_heredoc(t_heredoc *list)
{
	int	fd;

	while (list)
	{
		fd = open(list->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (FALSE);
		if (!fill_file_input(fd, *list))
		{
			unlink(list->filename);
			return (FALSE);
		}
		close(fd);
		list = list->next;
	}
	return (TRUE);
}
