/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/27 15:41:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data data;

	init_data(&data, argc, argv);
	if (!dup_envp(&data, envp))
		ft_printf("Error, duplicate envp failed\n");
	while (42)
	{
		data.input = get_input();
		if (!input_valid(&data))
		{
			ft_printf("Error: %d\n", data.curr_error);
			reset_data(&data);
			continue;
			// break;
		}
		data.prompts = split_pipe(data.input);
		ft_printf("Input parsed:$%s$\n", data.input);
		print_prompts(data.prompts);
		reset_data(&data);
		// continue;
		// break;
	}
	free_data(&data);
	return (0);
}
