/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 23:29:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*input;
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
		input = get_all_input();
		if (!input)
		{
			free_data(&data);
			ft_printf("-minishell: syntax error near unexpected token `|'\n");
			return (0);
		}
		format_data_input(&input, ms_trim_free(input));
		ft_printf("%s\n", input);
		data.input = limit_prompt_free(input);
		ft_printf("input formatted: %s\n", data.input);
		ft_printf("sub prompt count: %d\n", ms_count_prompt(data.input));
		tab = ms_split_pipe(data.input);
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
