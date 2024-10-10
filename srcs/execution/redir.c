/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:24:51 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/09 21:02:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	check_error_redir_in(t_redir_in *arg_rdr)
{
	while (arg_rdr)
	{
		if (ft_strncmp(arg_rdr->file, ".tmp", 4) == 0)
			return (FALSE); // heredoc file
		if (access(arg_rdr->file, F_OK) != 0 || access(arg_rdr->file,
				R_OK) != 0)
		{
			ft_printf("%s: Permission denied or No such file or directory\n",
				arg_rdr->file);
			return (TRUE);
		}
		arg_rdr = arg_rdr->next;
	}
	return (FALSE);
}
t_bool	check_error_redir_out(t_redir_out *arg_rdr)
{
	while (arg_rdr)
	{
		if (access(arg_rdr->file, F_OK) == 0)
		{
			if (arg_rdr->type == REDIR_APPEND && access(arg_rdr->file,
					W_OK) != 0)
			{
				ft_printf("%s: Permission denied, cannot write to file\n",
					arg_rdr->file);
				return (TRUE);
			}
		}
		arg_rdr = arg_rdr->next;
	}
	return (FALSE);
}

t_bool	check_redir_error(t_redir_in *arg_rdr_in, t_redir_out *arg_rdr_out)
{
	if (check_error_redir_in(arg_rdr_in))
		return (TRUE);
	if (check_error_redir_out(arg_rdr_out))
		return (TRUE);
	return (FALSE);
}

int	set_redir_out(t_redir_out *redir)
{
	int	fd_file;

	if (redir)
	{
		while (redir->next)
		{
			if (redir->type == REDIR_APPEND)
				fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND,
						0644);
			else if (redir->type == REDIR_TRUNC)
				fd_file = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (!fd_file)
				return (-1);
			close(fd_file);
			redir = redir->next;
		}
		if (redir->type == REDIR_APPEND)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redir->type == REDIR_TRUNC)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (!fd_file)
			return (-1);
		return (fd_file);
	}
	return (STDOUT_FILENO);
}

int	set_redir_in(t_redir_in *redir)
{
	int	fd_file;

	if (redir)
	{
		while (redir->next)
		{
			fd_file = open(redir->file, O_RDONLY);
			if (!fd_file)
				return (-1);
			close(fd_file);
			redir = redir->next;
		}
		fd_file = open(redir->file, O_RDONLY);
		if (!fd_file)
			return (-1);
		return (fd_file);
	}
	return (STDIN_FILENO);
}
