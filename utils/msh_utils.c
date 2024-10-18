/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:09 by saandria          #+#    #+#             */
/*   Updated: 2024/10/18 14:04:54 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_msh *msh)
{
	if (msh->envp)
		free_env(&msh->envp);
	free(msh);
}

void	error(void)
{
	perror("bash");
	exit(EXIT_FAILURE);
}

void	check_exit(t_msh *msh)
{
	if (ft_strncmp(msh->input, "exit", 4) == 0)
	{
		printf("exit\n");
		free_env(&msh->envp);
		free(msh->input);
		free(msh);
		exit(EXIT_SUCCESS);
	}
}

void	ms_init(t_msh **msh)
{
	(*msh)->envc = env_copy(&(*msh)->envp);
	(*msh)->token = ms_tokenizer((*msh)->input);
	(*msh)->token = join_token(&(*msh)->token);
	(*msh)->token = final_token(&(*msh)->token);
	print_token((*msh)->token);
	(*msh)->node = parse((*msh)->token);
	print_ast(&(*msh)->node);
}

t_bool	init_msh(t_msh **msh, int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(*msh)->input = NULL;
	(*msh)->heredoc = NULL;
	(*msh)->node = NULL;
	(*msh)->token = NULL;
	(*msh)->exit_status = EXIT_SUCCESS;
	(*msh)->envp = get_env(env);
	return (TRUE);
}
