/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:23 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/23 12:33:42 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_msh	msh;

	init_msh_ok(argc, argv, &msh);
	if (!dup_envp_ok(&msh, envp))
		exit_err_dup_env(&msh);
	run_msh(&msh);
	free_msh(&msh, TRUE);
	return (0);
}
