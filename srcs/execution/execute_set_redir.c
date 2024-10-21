/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_set_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:37:55 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 15:53:13 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool check_redir_in_ok(t_redir_in *redir)
{
	while (redir)
	{
		if (ft_strncmp(redir->file, ".msh_", 5) != 0) //* not heredoc file
		{
			if (access(redir->file, F_OK) != 0) //* not exists
				return (print_err_redir(FALSE));
			if (access(redir->file, R_OK) != 0) //* not readable
				return (print_err_redir(FALSE));
		}
		redir = redir->next;
	}
	return (TRUE);
}

t_bool check_redir_out_ok(t_redir_out *redir)
{
	while (redir)
	{
		if (access(redir->file, F_OK) == 0) //* exists
		{
			if (access(redir->file, W_OK) != 0) //* not writable
				return (print_err_redir(FALSE));
		}
		redir = redir->next;
	}
	return (TRUE);
}

t_bool set_redir_in_ok(t_redir_in *redir)
{
	int fd_rdr;

	while (redir)
	{
		fd_rdr = open(redir->file, O_RDONLY);
		if (!fd_rdr)
			return (print_err_redir(FALSE));
		dup2(fd_rdr, STDIN_FILENO);
		close(fd_rdr);
		redir = redir->next;
	}
	return (TRUE);
}

t_bool set_redir_out_ok(t_redir_out *redir)
{
	int fd_rdr;

	while (redir)
	{
		if (redir->type == RO_APPEND)
			fd_rdr = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redir->type == RO_TRUNC)
			fd_rdr = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (!fd_rdr)
			return (print_err_redir(FALSE));
		dup2(fd_rdr, STDOUT_FILENO);
		close(fd_rdr);
		redir = redir->next;
	}
	return (TRUE);
}

t_bool set_all_redir_ok(t_prompt *prompt)
{
	if (!check_redir_in_ok(prompt->redir_in_list))
		return (FALSE);
	if (!check_redir_out_ok(prompt->redir_out_list))
		return (FALSE);
	if (!set_redir_in_ok(prompt->redir_in_list))
		return (FALSE);
	if (!set_redir_out_ok(prompt->redir_out_list))
		return (FALSE);
	return (TRUE);
}
