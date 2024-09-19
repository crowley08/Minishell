/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 17:11:22 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*prompt;

	data_init(&data, argc, argv);
	if (!envp_dup(&data, envp))
	{
		ft_printf("Error, duplicate envp failed\n");
		free_data(&data);
	}
	while (TRUE)
	{
		prompt = readline("prompt > ");
		if (quote_opened(prompt))
			ft_printf("===> quote opened\n");
		data.prompt = ms_trim(prompt);
		free(prompt);
		break ;
	}
	ft_printf("prompt trimmed: %s\n", data.prompt);
	ft_printf("prompt number: %d, len: %d\n", ms_count_prompt(data.prompt),
		ft_strlen(data.prompt));
	free_data(&data);
	return (0);
}
