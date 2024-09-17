/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:18:21 by saandria          #+#    #+#             */
/*   Updated: 2024/09/17 22:38:59 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_token	*create_token(t_tokentype type, char *value, int *i)
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
	printf("%s\n", new_token->value);
	return (new_token);
}

static void	check_token_list(t_token **current, t_token *new)
{
	if (*current == NULL)
		*current = new;
	else
	{
		(*current)->next = new;
		*current = new;
	}
}

static t_token	*get_wordtok(char *s, int *i)
{
	t_token	*new_token;
	char	*value;
	int		start;

	start = *i;
	while (s[*i])
	{
		/*
		mbola tsy mety le quotes
		*/
		if (s[*i + 1] == '\'')
		{
			while (s[*i] && s[*i] != '\'')
				*i += 1;
			break ;
		}
		else if (s[*i + 1] == '\"')
		{
			while (s[*i] && s[*i] != '\"')
				*i += 1;
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
	if (!value)
		return (NULL);
	new_token = create_token(TOK_WORD, value, i);
	free(value);
	return (new_token);
}

static t_token	*check_token(char *s, int *i, t_token *new_token)
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

t_token	*ms_tokenizer(char *s)
{
	t_token	*current;
	t_token	*new_token;
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(s);
	current = NULL;
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
			new_token = get_wordtok(s, &i);
		print_token(new_token);
		check_token_list(&current, new_token);
	}
	return (new_token);
}
