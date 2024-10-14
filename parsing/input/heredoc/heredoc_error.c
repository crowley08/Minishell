/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:25:30 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:57:01 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	error_fork_heredoc(t_msh *msh, char *input)
{
	perror("Error: fork pid_heredoc() returned");
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}

t_bool	set_heredoc_error(t_error *error, t_error type)
{
	*error = type;
	return (T);
}

void	error_heredoc(t_msh *msh, char *input)
{
	perror("msh: heredoc error");
	free(input);
	free_msh_reset(msh);
}
