/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:18:21 by saandria          #+#    #+#             */
/*   Updated: 2024/10/16 18:05:12 by saandria         ###   ########.fr       */
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

	tmp = *token;
	while (*token)
	{
		if ((*token)->type == TOK_REDIRIN)
		{
			(*token)->value = ft_strjoin((*token)->value, " ");
			(*token)->value = ft_strjoin((*token)->value, (*token)->next->value);
			tmp2 = (*token)->next;
			(*token)->next = (*token)->next->next;
			free(tmp2->value);
			free(tmp2);
		}
		*token = (*token)->next;
	}
	*token = tmp;
	return (*token);
}

/*
//!!!TO DO
t_token	*final_token(t_token **token)
{
	
}
*/