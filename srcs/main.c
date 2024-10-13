/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 19:55:52 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_msh(t_msh *msh)
{
	char	*input;

	while (42)
	{
		input = get_input(msh);
		if (has_syntax_error(msh, input))
			continue ;
		if (has_heredoc_parse_input_error(msh, input))
			continue ;
		ft_printf("input parsed final: $%s$\n", msh->input);
		free_msh_reset(msh);
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
