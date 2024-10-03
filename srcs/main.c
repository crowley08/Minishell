/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/03 13:29:11 by arakotom         ###   ########.fr       */
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
		print_heredoc(heredoc);
		write(1, "\n\n", 2);
		if (!create_file_heredoc(heredoc, data.envp))
			ft_printf("Error, heredoc failed\n");
		ft_printf("before parsing heredoc:\n%s\n", data.input);
		data.input = get_new_input_heredoc(data.input, heredoc, TRUE);
		data.input = get_new_input_unquote(data.input, TRUE);
		ft_printf("After parsing heredoc:\n%s\n", data.input);
		free_heredoc_list(&heredoc);
		data.prompts = split_pipe(data.input);
		if (!data.prompts)
			ft_printf("Error, split input to prompts failed");
		print_prompts(data.prompts);
		reset_data(&data);
		// continue ;
		break ;
	}
	free_data(&data);
	return (0);
}
