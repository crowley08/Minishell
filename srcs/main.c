/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:25:12 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_msh(t_msh *msh)
{
	char	*line;

	while (42)
	{
		line = get_line(msh);
		free(line);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_msh	msh;

	init_msh(&msh, argc, argv, envp);
	run_msh(&msh);
	ft_printf("minishell down...\n");
	free_msh(&msh);
	return (0);
}
