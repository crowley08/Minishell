/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:51:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 20:01:27 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool		g_sig_int_heredoc;

void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_sig_int_heredoc = TRUE;
	close(STDIN_FILENO);
}

void	set_signal_handler_heredoc(void)
{
	struct sigaction	sa_int;

	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sa_int.sa_handler = &handle_heredoc_sigint;
	sigaction(SIGINT, &sa_int, NULL);
}

void	write_file_heredoc(int fd, char *line, t_bool exp_var, t_msh *msh)
{
	char	*value;

	while (line && *line)
	{
		if (*line == '$' && exp_var)
		{
			value = expand_var_heredoc(++line, msh);
			write(fd, value, ft_strlen(value));
			free(value);
			while (line && *line && (ft_isalnum(*line) || *line == '_'
					|| *line == '$' || *line == '?'))
				line++;
		}
		else
			write(fd, line++, 1);
	}
	write(fd, "\n", 1);
}

t_error_stt	create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc)
{
	char	*line;

	while (TRUE)
	{
		line = readline("> ");
		if (line == NULL)
		{
			if (g_sig_int_heredoc)
				return (HEREDOC_SIGINT);
			return (HEREDOC_EOF);
		}
		if (line && *line && ft_strncmp(line, heredoc->eof,
				ft_strlen(heredoc->eof) + 1) == 0)
		{
			free(line);
			close(fd);
			return (NOTHING);
		}
		write_file_heredoc(fd, line, heredoc->exp_var, msh);
		free(line);
	}
}

int	launch_heredoc(t_msh *msh)
{
	t_error_stt	error;
	t_heredoc	*heredoc;
	int			fd;

	error = NOTHING;
	heredoc = msh->heredoc;
	while (heredoc)
	{
		set_signal_handler_heredoc();
		fd = open(heredoc->tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0 && set_heredoc_error(&error, HEREDOC_FD))
			break ;
		error = create_file_heredoc(fd, msh, heredoc);
		if (error != NOTHING)
			break ;
		heredoc = heredoc->next;
	}
	return (error);
}
