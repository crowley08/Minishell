/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:09 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 23:30:02 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	check_exit(t_msh *msh)
{
	if (ft_strcmp(msh->input, "exit") == 0)
	{
		printf("exit\n");
		free(msh->input);
		free(msh);
		exit(EXIT_SUCCESS);
	}
}

void	init_msh(t_msh **msh, char **env)
{
	(*msh)->envp = get_env(env);
	(*msh)->envc = env_copy(&(*msh)->envp);
	(*msh)->token = ms_tokenizer((*msh)->input);
	(*msh)->node = parse((*msh)->token);
}

int	count_pipe(t_msh *msh)
{
	int		i;
	int		pipe;
	char	*s;

	i = -1;
	pipe = 0;
	s = msh->input;
	while (s[++i])
		pipe++;
	return (pipe);
}
