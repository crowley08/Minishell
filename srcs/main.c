/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/03 22:53:42 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	char	*line;

	init_data(&data, argc, argv);
	if (!dup_envp(&data, envp))
		ft_printf("Error, duplicate envp failed\n");
	while (42)
	{
		line = get_input();
		data.input = parse_input_var(line, data.envp);
		if (!(data.input))
		{
			reset_data(&data);
			continue ;
		}
		data.prompts = split_pipe(data.input);
		if (!data.prompts)
			ft_printf("Error, split input to prompts failed");
		print_prompts(data.prompts);
		reset_data(&data);
		continue ;
		// break ;
	}
	free_data(&data);
	return (0);
}
