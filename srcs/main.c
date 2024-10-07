/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:53:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 11:48:09 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data data;
	char *line;
	char **prompt;

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
			continue;
		}
		prompt = split_pipe(data.input);
		if (!prompt)
			ft_printf("Error, split input to prompts failed\n");
		if (!set_prompt_data(&data, split_pipe(data.input)))
			ft_printf("Error, set prompt data\n");
		print_prompts(prompt);
		ft_free_tab_str(prompt);
		reset_data(&data);
		continue;
		// break ;
	}
	free_data(&data);
	return (0);
}
