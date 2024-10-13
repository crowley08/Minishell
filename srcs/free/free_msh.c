/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:30:12 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 19:53:00 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_msh(t_msh *msh)
{
	if (msh->env_list)
		free_env_list(&(msh->env_list));
	if (msh->input)
		free(msh->input);
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
}

void	free_msh_keep_file(t_msh *msh)
{
	if (msh->env_list)
		free_env_list(&(msh->env_list));
	if (msh->input)
		free(msh->input);
	if (msh->heredoc)
		free_heredoc_list_keep_file(&(msh->heredoc));
}

void	free_msh_reset(t_msh *msh)
{
	ft_printf("Reset msh... exit status => %d\n", msh->exit_status);
	if (msh->input)
		free(msh->input);
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
	msh->input = NULL;
	msh->heredoc = NULL;
}

void	free_msh_syntax(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
}

void	free_msh_heredoc(t_msh *msh, char *input)
{
	free(input);
	free_msh_keep_file(msh);
}
