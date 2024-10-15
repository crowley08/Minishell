/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:00:08 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 16:44:50 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	set_error_redir(t_error_stt type)
{
	if (type == NOTHING)
		return (FALSE);
	if (type == EXEC_REDIR_IN_404)
		perror("msh: No such file or directory");
	else if (type == EXEC_REDIR_IN_401)
		perror("msh: Permission to read denied");
	else if (type == EXEC_REDIR_OUT_401)
		perror("msh: Permission to write denied");
	else if (type == EXEC_REDIR_IN_500)
		perror("msh: Can not open file");
	else if (type == EXEC_REDIR_OUT_500)
		perror("msh: Can not open or create file");
	return (TRUE);
}

t_bool	has_error_redir_in(t_redir_in *redir)
{
	while (redir)
	{
		if (!(redir->file))
			return (set_error_redir(NOTHING));
		if (ft_strncmp(redir->file, ".msh_", 5) == 0)
			return (set_error_redir(NOTHING));
		if (access(redir->file, F_OK) != 0)
		{
			if (access(redir->file, R_OK) != 0)
				return (set_error_redir(EXEC_REDIR_IN_401));
			else
				return (set_error_redir(NOTHING));
		}
		else
			return (set_error_redir(EXEC_REDIR_IN_404));
		redir = redir->next;
	}
	return (set_error_redir(NOTHING));
}

t_bool	has_error_redir_out(t_redir_out *redir)
{
	while (redir)
	{
		if (!(redir->file))
			return (TRUE);
		if (access(redir->file, F_OK) == 0)
		{
			if (access(redir->file, W_OK) != 0)
				return (set_error_redir(EXEC_REDIR_OUT_401));
			else
				return (set_error_redir(NOTHING));
		}
		redir = redir->next;
	}
	return (set_error_redir(NOTHING));
}

t_bool	has_error_redir_exec(t_prompt *prompt)
{
	if (has_error_redir_in(prompt->redir_in_list))
		return (TRUE);
	if (has_error_redir_out(prompt->redir_out_list))
		return (TRUE);
	return (FALSE);
}
