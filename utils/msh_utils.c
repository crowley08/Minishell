/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:09 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 15:33:14 by saandria         ###   ########.fr       */
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
	if (ft_strncmp(msh->input, "exit", 4) == 0)
	{
		printf("exit\n");
		free_env(&msh->envp);
		free(msh->input);
		free(msh);
		exit(EXIT_SUCCESS);
	}
}

void	init_msh(t_msh **msh)
{
	(*msh)->envc = env_copy(&(*msh)->envp);
	(*msh)->token = ms_tokenizer((*msh)->input);
//	(*msh)->expand = ms_expand(&(*msh)->token);
//	free_tokens(&(*msh)->token);
//	print_token((*msh)->expand);
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
