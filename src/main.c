/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/09/27 15:19:35 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_msh	*msh;
//	pid_t	pid;

	(void)ac;
	(void)av;
	msh = malloc(sizeof(t_msh));
	msh->envp = get_env(env);
	ms_signal();
	while (42)
	{
		msh->envc = env_copy(env);
		msh->input = readline("\033[1;91m$>\033[0m ");
		if (!msh->input)
		{
			free(msh->input);
			return (0);
		}
		msh->token = ms_tokenizer(msh->input);
		msh->node = parse(msh->token);
	//	print_token(msh->token);
		print_ast(&msh->node);
	/*
		pid = fork();
		if (pid == 0)
			exec(&msh->token, msh->envc);
		waitpid(pid, NULL, 0);
	*/
		add_history(msh->input);
		free_minishell(msh);
	}
	free(msh);
	return (0);
}

	/*
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "env") == 0)
			print_env_list(envp);
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		*/
