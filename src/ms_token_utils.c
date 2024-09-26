/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:38:27 by saandria          #+#    #+#             */
/*   Updated: 2024/09/26 11:05:21 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ms_istoken(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("TOKEN:\n");
		printf("\tType: %d\n", tmp->type);
		printf("\tValue: %s\n", tmp->value);
		tmp = tmp->next;
	}
}

int	is_in_simple_quotes(char *s, int *i)
{
	int	j;

	j = *i;
	while (s[j])
	{
		j++;
		if (s[j] == '\'')
			return (j);
	}
	return (0);
}

int	is_in_double_quotes(char *s, int *i)
{
	int	j;

	j = *i;
	while (s[j])
	{
		j++;
		if (s[j] == '"')
			return (j);
	}
	return (0);
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
