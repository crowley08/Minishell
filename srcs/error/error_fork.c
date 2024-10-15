/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:32:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:50:09 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_fork_syntax(t_msh *msh, char *input)
{
	perror("Error: fork pid_syntax() returned");
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}

void	error_fork_heredoc(t_msh *msh, char *input)
{
	perror("Error: fork pid_heredoc() returned");
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}

t_bool	error_fork_execute(void)
{
	perror("Error: fork pid_execute() returned");
	return (EXIT_FAILURE);
}
