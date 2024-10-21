/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:47:38 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:57:58 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

volatile sig_atomic_t	g_sig_int_heredoc;

void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_sig_int_heredoc = 2;
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
			value = expand_var(++line, msh);
			write(fd, value, ft_strlen(value));
			free(value);
			if (line && (*line == '$' || *line == '?'))
				line++;
			else
				while (line && *line && (ft_isalnum(*line) || *line == '_'))
					line++;
		}
		else
			write(fd, line++, 1);
	}
	write(fd, "\n", 1);
}

t_error_state	create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc)
{
	char	*line;

	while (42)
	{
		line = readline("> ");
		if (line == NULL)
		{
			if (g_sig_int_heredoc == 2)
				return (HDC_CTRL_C);
			return (HDC_CTRL_D);
		}
		if (line && *line && ft_strncmp(line, heredoc->eof,
				ft_strlen(heredoc->eof) + 1) == 0)
		{
			free(line);
			return (NOTHING);
		}
		write_file_heredoc(fd, line, heredoc->exp_var, msh);
		free(line);
	}
}

t_error_state	check_parser_heredoc(t_msh *msh)
{
	t_heredoc		*heredoc;
	t_error_state	error;
	int				fd;

	heredoc = msh->heredoc_list;
	while (heredoc)
	{
		set_signal_handler_heredoc();
		fd = open(heredoc->tmp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (HDC_FD);
		error = create_file_heredoc(fd, msh, heredoc);
		close(fd);
		if (error != NOTHING)
			break ;
		heredoc = heredoc->next;
	}
	return (error);
}
