/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 14:15:56 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data_init(&data, argc, argv);
	if (!envp_dup(&data, envp))
	{
		ft_printf("Error, duplicate envp failed\n");
		free_data(&data);
	}
	while (TRUE)
	{
		data.prompt = readline("prompt > ");
		if (quote_opened(data.prompt))
			ft_printf("===> quote opened\n");
		break ;
	}
	free_data(&data);
	return (0);
}
