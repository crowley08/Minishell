/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:51:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:52:44 by arakotom         ###   ########.fr       */
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

t_bool	set_heredoc_error(t_error_stt *error, t_error_stt type)
{
	*error = type;
	return (TRUE);
}

char	*expand_var_heredoc(char *line, t_msh *msh)
{
	t_env	*env;
	char	*name;
	int		i;

	if (*line == '?')
		return (ft_itoa(msh->exit_status));
	else if (*line == '$')
		return (ft_strdup("288"));
	else if (ft_isspace(*line))
		return (ft_strdup("$"));
	i = 0;
	while (line && line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	if (i == 0)
		return (ft_strdup(""));
	name = ft_substr(line, 0, i);
	env = get_env(name, msh->env_list);
	free(name);
	if (env)
		return (ft_strdup(env->value));
	return (ft_strdup(""));
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
		ft_printf("line: %s, eof: %s\n", line, heredoc->eof);
		if (line && *line && ft_strncmp(line, heredoc->eof,
				ft_strlen(heredoc->eof) + 1) == 0)
		{
			free(line);
			close(fd);
			ft_printf("stop\n");
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
