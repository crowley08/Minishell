/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:44:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_msh	msh;

	init_msh(&msh, argc, argv, envp);
	ft_printf("minishell down...\n");
	free_msh(&msh);
	return (0);
}
