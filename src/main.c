/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:05 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	run_msh(t_msh **msh)
{
	char	*input;

	while (42)
	{
		input = get_input(*msh);
		if (has_syntax_error(*msh, input))
			continue ;
		if (has_heredoc_parse_input_error(*msh, input))
			continue ;
		printf("input parsed final: $%s$\n", (*msh)->input);
		ms_init(msh);
		exec_main(*msh);
		free_msh_reset(*msh);
		free_minishell(*msh);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_msh	*msh;

	msh = (t_msh *)malloc(sizeof(t_msh));
	init_msh(&msh, argc, argv, env);
	run_msh(&msh);
	free_msh(msh);
	free_all(msh);
}

/*
int	main(int ac, char **av, char **env)
{
	t_msh	*msh;

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
		ms_init(&msh);
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
