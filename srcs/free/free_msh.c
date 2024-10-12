/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:30:12 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 17:30:06 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_msh(t_msh *msh)
{
	if (msh->env_list)
		free_env_list(&(msh->env_list));
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
}

void free_msh_reset(t_msh *msh)
{
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
}

void free_msh_syntax(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
}

void free_msh_heredoc(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
}
