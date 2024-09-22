/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 12:47:28 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*prompt;
	char	**tab;
	int		i;

	data_init(&data, argc, argv);
	if (!envp_dup(&data, envp))
	{
		ft_printf("Error, duplicate envp failed\n");
		free_data(&data);
	}
	free(NULL);
	while (TRUE)
	{
		ft_printf("\n\n");
		// prompt = readline("prompt > ");
		prompt = strdup("echo | d |ls | cat");
		if (quote_opened(prompt))
		{
			ft_printf("===> quote opened\n");
			free(prompt);
		}
		format_data_prompt(&(data.prompt), ms_trim_free(prompt));
		ft_printf("prompt formatted: %s\n", data.prompt);
		ft_printf("sub prompt count: %d\n", ms_count_prompt(data.prompt));
		tab = ms_split_pipe(data.prompt);
		if (tab)
		{
			i = 0;
			while (tab[i])
			{
				ft_printf("====> Prompt %d = %s\n", i + 1, tab[i]);
				i++;
			}
			ft_free_tab_str(tab);
		}
		break ;
	}
	free_data(&data);
	return (0);
}
