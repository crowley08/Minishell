/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:28:48 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:51:47 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_msh_heredoc(t_msh *msh, char *input)
{
	free(input);
	free_msh_keep_file(msh);
}

void	free_msh_keep_file(t_msh *msh)
{
	if (msh->envp)
		free_env(&(msh->envp));
	if (msh->input)
		free(msh->input);
	if (msh->heredoc)
		free_heredoc_list_keep_file(&(msh->heredoc));
}

void	free_msh(t_msh *msh)
{
	if (msh->envp)
		free_env(&(msh->envp));
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
}

//free(msh);
//	free_minishell(msh);

void	free_msh_reset(t_msh *msh)
{
	printf("Reset msh... exit status => %d\n", msh->exit_status);
	if (msh->input)
		free(msh->input);
	if (msh->heredoc)
		free_heredoc_list(&(msh->heredoc));
	msh->input = NULL;
	msh->heredoc = NULL;
}
