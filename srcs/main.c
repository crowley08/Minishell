/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 15:49:27 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data data;
	char *line;

	init_data(&data, argc, argv);
	if (!dup_envp(&data, envp))
		ft_printf("Error, duplicate envp failed\n");
	while (42)
	{
		line = get_input();
		data.input = parse_input_var(line, data.envp);
		ft_printf("Parsed: %s\n", data.input);
		if (!(data.input))
		{
			reset_data(&data);
			break;
			// continue ;
		}
		if (!set_prompt_data(&data, split_pipe(data.input)))
			ft_printf("Error, set prompt data\n");
		// print_prompts(data.prompt);
		exec_list_prompt(data.prompt, data.envp);
		reset_data(&data);
		// continue ;
		break;
	}
	free_data(&data);
	return (0);
}
