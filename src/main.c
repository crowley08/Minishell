/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 17:07:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_msh *msh)
{
	free_env(&msh->envp);
	free(msh);
}

int	main(int ac, char **av, char **env)
{
	t_msh	*msh;
	char	*line;

	(void)ac;
	(void)av;
	msh = malloc(sizeof(t_msh));
	msh->envp = get_env(env);
	while (42)
	{
		ms_signal();
		line = get_input();
		msh->input = parse_input_var(line, msh->envp);
		if (!msh->input)
		{
			free(msh->input);
			free_all(msh);
			return (0);
		}
		printf("%s\n", msh->input);
		check_exit(msh);
		init_msh(&msh);
		exec_main(msh);
		add_history(msh->input);
		free_minishell(msh);
	}
	free_all(msh);
	return (0);
}

/*
int	main(int ac, char **av, char **env)
{
	t_msh	*msh;
	char	*line;

	(void)ac;
	(void)av;
	msh = malloc(sizeof(t_msh));
	msh->envp = get_env(env);
	while (42)
	{
		ms_signal();
		msh->input = readline("\033[1;91m$>\033[0m ");
		if (!msh->input)
		{
			free(msh->input);
			free_all(msh);
			return (0);
		}
		check_exit(msh);
		init_msh(&msh);
		exec_main(msh);
		add_history(msh->input);
		free_minishell(msh);
	}
	free_all(msh);
	return (0);
}
*/
	/*
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "env") == 0)
			print_env_list(envp);
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		print_ast(&msh->node);
		*/
