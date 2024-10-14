/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:17:28 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:45:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*set_filename(int i)
{
	char	*index;
	char	*filename;

	index = ft_itoa(i);
	filename = ft_strjoin(".msh_", index);
	free(index);
	return (filename);
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
