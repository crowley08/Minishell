/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data		data;
	t_heredoc	*heredoc;

	init_data(&data, argc, argv);
	if (!dup_envp(&data, envp))
		ft_printf("Error, duplicate envp failed\n");
	while (42)
	{
		data.input = get_input();
		heredoc = get_all_heredoc(data.input);
		// print_heredoc(heredoc);
		if (!create_file_heredoc(heredoc))
			ft_printf("Error, heredoc fails\n");
		free_heredoc_list(&heredoc);
		// data.prompts = split_pipe(data.input);
		reset_data(&data);
		// continue ;
		break ;
	}
	free_data(&data);
	return (0);
}
