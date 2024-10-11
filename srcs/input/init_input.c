/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:50:14 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:58:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_line(t_msh *msh)
{
	char	*line;
	char	*input;

	while (42)
	{
		set_signal_handler();
		line = readline("\e[33mminishell$ \e[0m");
		if (line == NULL)
			exit_msh_sig(msh);
		if (is_empty_line(line))
			continue ;
		add_history(line);
		input = trim_sp_all(line);
		free(line);
		ft_printf("input: $%s$\n", input);
		free(input);
	}
}
