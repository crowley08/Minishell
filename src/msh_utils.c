/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:09 by saandria          #+#    #+#             */
/*   Updated: 2024/09/27 16:09:41 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_minishell(t_msh *msh)
{
	free_spl(msh->envc);
	free_tokens(&msh->token);
	free_env(&msh->envp);
	free(msh->input);
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
