/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/09/16 11:34:10 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*s;

	ms_signal();
	while (42)
	{
		s = readline("\033[1;91m$>\033[0m ");
		if (!s)
		{
			free(s);
			return (0);
		}
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		printf("%s\n", s);
		add_history(s);
		free(s);
	}
	return (0);
}
