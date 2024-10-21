/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_re_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:39:40 by saandria          #+#    #+#             */
/*   Updated: 2024/10/21 08:38:04 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*join_token(t_token **token)
{
	t_token	*tmp;
	t_token	*tmp2;
	char	*str;

	tmp = *token;
	while (*token)
	{
		if ((*token)->type == TOK_REDIRIN || (*token)->type == TOK_REDIROUT
			|| (*token)->type == TOK_APPEND)
		{
			str = ft_strjoin((*token)->value, " ");
			tmp2 = (*token)->next;
			free((*token)->value);
			(*token)->value = ft_strjoin(str, tmp2->value);
			free(str);
			tmp2->prev->next = tmp2->next;
			if (tmp2->next != NULL)
				tmp2->next->prev = tmp2->prev;
			free(tmp2->value);
			free(tmp2);
		}
		*token = (*token)->next;
	}
	*token = tmp;
	return (*token);
}

t_token	*re_create(t_tokentype type, char *value)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->value = ft_strdup(value);
	new_token->next = NULL;
	return (new_token);
}

static void	inverse_nodes(t_token *node1, t_token *node2)
{
	char	*tmp;
	int		tmp1;

	tmp1 = node1->type;
	tmp = node1->value;
	node1->type = node2->type;
	node1->value = node2->value;
	node2->type = tmp1;
	node2->value = tmp;
}

static int	is_redirection(t_tokentype type)
{
	if (type == TOK_APPEND || type == TOK_REDIRIN || type == TOK_REDIROUT)
		return (1);
	return (0);
}

t_token	*final_token(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	while (*token)
	{
		if (*token && (*token)->type == TOK_WORD && (*token)->next
			&& is_redirection((*token)->next->type))
		{
			inverse_nodes((*token), (*token)->next);
			*token = tmp;
		}
		*token = (*token)->next;
	}
	*token = tmp;
	return (*token);
}
