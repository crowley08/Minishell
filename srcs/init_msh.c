/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:06:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:43:49 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	init_msh(t_msh *msh, int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	if (!dup_envp(msh, envp))
		error_dup_env(msh);
	return (TRUE);
}
