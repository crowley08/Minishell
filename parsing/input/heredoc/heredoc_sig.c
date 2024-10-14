/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:11:51 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:45:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool		g_sig_int_heredoc;

t_error	create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc)
{
	char	*line;

	while (T)
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

void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_sig_int_heredoc = T;
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
