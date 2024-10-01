/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:46:35 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 22:37:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env(t_env **env)
{
	t_env	*current;
	t_env	*next;

	current = *env;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
	*env = NULL;
	free(current);
	current = NULL;
	next = NULL;
	return ;
}

void	free_spl(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

void	free_tokens(t_token **t)
{
	t_token	*current;
	t_token	*next;

	current = *t;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*t = NULL;
	free(current);
	current = NULL;
	next = NULL;
	return ;
}

void	free_node(t_node **node)
{
	char	**cmd;

	cmd = NULL;
	if (!*node)
		return ;
	if ((*node)->cmd)
	{
		cmd = (*node)->cmd;
		free_spl(cmd);
	}
	free_node(&(*node)->left);
	free_node(&(*node)->right);
	free(*node);
}

void	free_minishell(t_msh *msh)
{
	free_spl(msh->envc);
	free_tokens(&msh->token);
	free_env(&msh->envp);
	free_node(&msh->node);
	free(msh->input);
}
