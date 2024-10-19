/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:26:27 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:05:31 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_node	*dup_redir_token(t_token **token, t_nodetype type)
{
	t_node	*node;
	t_bool	do_free;
	int		i;

	i = -1;
	node = init_node(type);
	node->cmd = ft_split((*token)->value, ' ');
	do_free = T;
	while (node->cmd[++i])
		node->cmd[i] = un_quote(node->cmd[i], do_free);
	return (node);
}

static t_node	*dup_token(t_token **token)
{
	t_node	*node;
	char	*tmp;
	t_bool	do_free;
	int		i;
	int		j;

	node = init_node(CMD_NODE);
	i = count_token_word(*token);
	node->cmd = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	do_free = T;
	while (*token && (*token)->type == TOK_WORD)
	{
		tmp = ft_strdup((*token)->value);
		node->cmd[j] = un_quote(tmp, do_free);
		j++;
		*token = (*token)->next;
	}
	node->cmd[j] = NULL;
	return (node);
}

static t_node	*parse_token(t_token **token)
{
	t_node	*left;
	t_node	*node;

	left = dup_token(token);
	if (*token && ((*token)->type == TOK_PIPE
			|| (*token)->type == TOK_REDIROUT
			|| (*token)->type == TOK_APPEND
			|| (*token)->type == TOK_REDIRIN))
	{
		if ((*token)->type == TOK_PIPE)
			node = init_node(PIPE_NODE);
		else if ((*token)->type == TOK_APPEND)
			node = dup_redir_token(token, APPEND_NODE);
		else if ((*token)->type == TOK_REDIROUT)
			node = dup_redir_token(token, REDIR_OUT_NODE);
		else
			node = dup_redir_token(token, REDIR_IN_NODE);
		node->left = left;
		*token = (*token)->next;
		node->right = parse_token(token);
		return (node);
	}
	return (left);
}

t_node	*parse(t_token *token)
{
	t_node	*node;
	t_token	*tmp;

	tmp = token;
	node = parse_token(&tmp);
	free_tokens(&token);
	return (node);
}
