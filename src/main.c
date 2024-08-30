/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/08/30 21:17:19 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void handle(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	printf("\n\033[1;91m$>\033[0m ");
}

int	main(void)
{
	char	*s;

	signal(SIGINT, handle);
	while (1)
	{
		s = readline("\033[1;91m$>\033[0m ");
		if (strcmp(s, "exit") == 0)
			break ;
		printf("%s\n", s);
		add_history(s);
		free(s);
	}
	return (0);	
}
