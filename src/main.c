/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/09/25 16:10:17 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_token	*token;
	t_env	*envp;
	char	**envc;
	pid_t	pid;

	(void)ac;
	(void)av;
	envp = get_env(env);
	ms_signal();
	while (42)
	{
		envc = env_copy(env);
		s = readline("\033[1;91m$>\033[0m ");
		if (!s)
		{
			free(s);
			return (0);
		}
		token = ms_tokenizer(s);
		pid = fork();
		if (pid == 0)
			exec(&token, envc);
		/*
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "env") == 0)
			print_env_list(envp);
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		*/
		waitpid(pid, NULL, 0);
		add_history(s);
		free_spl(envc);
		free_tokens(&token);
		free_env(&envp);
		free(s);
	}
	return (0);
}
