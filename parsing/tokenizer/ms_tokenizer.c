/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:18:21 by saandria          #+#    #+#             */
/*   Updated: 2024/10/18 18:35:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*create_token(t_tokentype type, char *value, int *i)
{
	t_token	*new_token;

	(void)i;
	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->value = ft_strdup(value);
	new_token->next = NULL;
	new_token->prev = NULL;
	*i += 1;
	return (new_token);
}

t_token	*get_wordtok(char *s, int *i, t_token *new_token)
{
	char	*value;
	int		start;

	start = *i;
	while (s[*i])
	{
		if (s[*i] == '\'' || s[*i] == '"')
		{
			check_inquotes(s, i);
			if (!ms_isspace(s[*i]) && !ms_istoken(s[*i]))
				*i += 1;
			else
				break ;
		}
		else
		{
			while (s[*i] && !ms_isspace(s[*i]) && !ms_istoken(s[*i]))
				*i += 1;
			break ;
		}
	}
	value = ft_substr(s, start, *i - start);
	new_token = create_token(TOK_WORD, value, i);
	free(value);
	return (new_token);
}

t_token	*check_token(char *s, int *i, t_token *new_token)
{
	if (s[*i] == '|')
		new_token = create_token(TOK_PIPE, "|", i);
	else if (s[*i] == '>')
	{
		if (s[*i + 1] == '>')
		{
			new_token = create_token(TOK_APPEND, ">>", i);
			(*i)++;
		}
		else
			new_token = create_token(TOK_REDIROUT, ">", i);
	}
	else if (s[*i] == '<')
	{
		if (s[*i + 1] == '<')
		{
			new_token = create_token(TOK_HEREDOC, "<<", i);
			(*i)++;
		}
		else
			new_token = create_token(TOK_REDIRIN, "<", i);
	}
	return (new_token);
}

void	add_token(t_token **token, t_token *new)
{
	t_token	*current;

	if (!*token)
		*token = new;
	else
	{
		current = *token;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
}

t_token	*ms_tokenizer(char *s)
{
	t_token	*new_token;
	t_token	*token;
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(s);
	token = NULL;
	while (ms_isspace(s[i]))
		i++;
	token = check_if(token, s, &i);
	while (i < len)
	{
		if (ms_isspace(s[i]))
		{
			i++;
			continue ;
		}
		else if (ms_istoken(s[i]))
			new_token = check_token(s, &i, new_token);
		else
			new_token = get_wordtok(s, &i, new_token);
		add_token(&token, new_token);
	}
	return (token);
}

t_token	*join_token(t_token **token)
{
	t_token	*tmp;
	t_token	*tmp2;
	char	*str;

	tmp = *token;
	while (*token)
	{
		if ((*token)->type == TOK_REDIRIN)
		{
			str = ft_strjoin((*token)->value, " ");
			tmp2 = (*token)->next;
			free((*token)->value);
			(*token)->value = ft_strjoin(str, tmp2->value);
			free(str);
			tmp2->prev->next = tmp2->next;
	//		(*token)->next = tmp2->next;
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
	t_token	*prev;
	t_token	*next;
	t_token	*head;

	//prev = NULL;
	//next = NULL;
	head = NULL;
	/*
	if ((node1)->prev == NULL)
	{
		head = node1;
	//	prev = (node2)->prev;
		next = (node2)->next;
		(node1)->prev = (node2);
		(node1)->next = next;
		(node2)->prev = NULL;
		(node2)->next = node1;
		head = node2;
	}
	*/
	//else
	//{
	if (node1->prev == NULL)
		head = node1;
	prev = (node1)->prev;
	next = (node2)->next;
	if (prev != NULL)
		prev->next = node2;
	if (next != NULL)
		next->prev = node1;
	(node1)->prev = node2;
	(node1)->next = next;
	(node2)->prev = prev;
	(node2)->next = node1;
	if (head != NULL)
		head = node2;
	//}
}

t_token	*final_token(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	while (*token)
	{
		if (*token && (*token)->type == TOK_WORD && ((*token)->next && (*token)->next->type == TOK_REDIRIN))
			inverse_nodes((*token), (*token)->next);
		*token = (*token)->next;
	}
	*token = tmp;
	return (*token);
}
