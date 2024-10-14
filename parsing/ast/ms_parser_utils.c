/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:49:33 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 10:26:17 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	print_ast(t_node **node)
{
	if (!*node)
		return ;
	printf("type : %d\n", (*node)->type);
	if ((*node)->cmd)
		printf("%s\n", (*node)->cmd[0]);
	print_ast(&(*node)->left);
	print_ast(&(*node)->right);
}
