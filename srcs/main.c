/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 16:37:09 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*list_env;
	char	*prompt;

	(void)argv;
	(void)argc;
	if (!(list_env = envp_dup(envp)))
	{
		ft_printf("Error: Failed to duplicate environment variables\n");
	}
	while (true)
	{
		prompt = readline("prompt > ");
		ft_printf("input = %s\n", prompt);
		if (is_quote_opened(prompt))
		{
			free(prompt);
			ft_printf("===> quote opened\n");
			break ;
		}
		free(prompt);
	}
	env_free_list(list_env);
	return (0);
}
