/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_set_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:33:02 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 17:22:37 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	set_redir_stdout_error(t_redir_out *redir)
{
	int	fd_file;

	if (!redir)
		return (set_error_redir(NOTHING));
	while (redir->next)
	{
		if (redir->type == RO_APPEND)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redir->type == RO_TRUNC)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (!fd_file)
			return (set_error_redir(EXEC_REDIR_OUT_500));
		close(fd_file);
		redir = redir->next;
	}
	if (redir->type == RO_APPEND)
		fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (redir->type == RO_TRUNC)
		fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (!fd_file)
		return (set_error_redir(EXEC_REDIR_OUT_500));
	dup2(fd_file, STDOUT_FILENO);
	close(fd_file);
	return (set_error_redir(NOTHING));
}

t_bool	set_redir_stdin_error(t_redir_in *redir)
{
	int	fd_file;

	if (!redir)
		return (set_error_redir(NOTHING));
	while (redir->next)
	{
		fd_file = open(redir->file, O_RDONLY);
		if (!fd_file)
			return (set_error_redir(EXEC_REDIR_IN_500));
		close(fd_file);
		redir = redir->next;
	}
	fd_file = open(redir->file, O_RDONLY);
	if (!fd_file)
		return (set_error_redir(EXEC_REDIR_IN_500));
	dup2(fd_file, STDIN_FILENO);
	close(fd_file);
	return (set_error_redir(NOTHING));
}

t_bool	set_redir_std_in_out_error(t_prompt *prompt)
{
	if (set_redir_stdin_error(prompt->redir_in_list))
		return (TRUE);
	if (set_redir_stdout_error(prompt->redir_out_list))
		return (TRUE);
	return (FALSE);
}
