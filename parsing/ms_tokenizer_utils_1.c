/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:55:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/07 17:44:17 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	check_inquotes(char *s, int *i)
{
	if (s[*i] == '\'')
	{
		if (is_in_simple_quotes(s, i))
			*i = is_in_simple_quotes(s, i);
	}
	else if (s[*i] == '"')
	{
		if (is_in_double_quotes(s, i))
			*i = is_in_double_quotes(s, i);
	}
}

t_token	*check_if(t_token *token, char *s, int *i)
{
	if (ms_istoken(s[*i]))
		token = check_token(s, i, token);
	else
		token = get_wordtok(s, i, token);
	return (token);
}
