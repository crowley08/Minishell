/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:06:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:56:11 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_msh_sigeof(t_msh *msh)
{
	free_msh(msh);
	ft_printf("^D\n");
	exit(EXIT_SUCCESS);
}

void	exit_msh_exit(t_msh *msh, char *input)
{
	free_msh(msh);
	free(input);
	ft_printf("exit\n");
	exit(EXIT_SUCCESS);
}

t_bool	init_msh(t_msh *msh, int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	msh->heredoc = NULL;
	msh->exit_status = EXIT_SUCCESS;
	if (!dup_envp(msh, envp))
		error_dup_env(msh);
	return (TRUE);
}
