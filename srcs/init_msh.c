/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:06:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:04:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_msh_sig(t_msh *msh)
{
	free_msh(msh);
	ft_printf("^D\n");
	exit(EXIT_SUCCESS);
}

t_bool	init_msh(t_msh *msh, int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	if (!dup_envp(msh, envp))
		error_dup_env(msh);
	return (TRUE);
}
