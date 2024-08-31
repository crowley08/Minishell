/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/08/31 04:15:28 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av)
{
	char	*s;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	if (ac > 0)
	{	
		while (42)
		{
			s = readline("\033[1;91m$>\033[0m ");
			if (!s)
			{
				free(s);
				return (0);
			}
			if (strcmp(s, "exit") == 0)
				break ;
			else if (strcmp(s, "pwd") == 0)
				s = getcwd(NULL, 0);
			printf("%s\n", s);
			add_history(s);
			free(s);
		}
	return (0);
	}
}
