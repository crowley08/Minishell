/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 00:26:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*prompt;
	char	**tab;
	int		i;

	i = 0;
	data_init(&data, argc, argv);
	if (!envp_dup(&data, envp))
	{
		ft_printf("Error, duplicate envp failed\n");
		free_data(&data);
	}
	free(NULL);
	while (TRUE)
	{
		// prompt = readline("	prompt > ");
		prompt = strdup("echo 'salut'||\" cat | ls \" lol");
		if (quote_opened(prompt))
		{
			ft_printf("===> quote opened\n");
			free(prompt);
		}
		format_data_prompt(&(data.prompt), ms_trim_free(prompt));
		ft_printf("prompt formatted: %s\n", data.prompt);
		ft_printf("cmd prompt number: %d\n", ms_count_prompt(data.prompt));
		tab = ms_split_pipe(data.prompt);
		if (tab)
		{
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
