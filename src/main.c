/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/09/19 11:21:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_token	*token;
	t_env	*envp;

	(void)ac;
	(void)av;
	envp = get_env(env);
	ms_signal();
	while (42)
	{
		s = readline("\033[1;91m$>\033[0m ");
		token = ms_tokenizer(s);
		if (!s)
		{
			free(s);
			return (0);
		}
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "env") == 0)
			print_env_list(envp);
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		add_history(s);
		free_tokens(token);
		free(s);
	}
	return (0);
}
