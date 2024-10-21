/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:23:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 09:55:30 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int next_value_len(char *input)
{
	int len;
	t_quote quote;

	len = 0;
	if (is_redir(input[len]))
	{
		len++;
		if (is_redir(input[len]) && input[len] == input[len - 1])
			len++;
		return (len);
	}
	init_quote(&quote);
	while (input && input[len])
	{
		update_quote(input[len], &quote);
		if (quote_closed(quote) && (ft_isspace(input[len]) || is_redir(input[len])))
			break;
		len++;
	}
	return (len);
}

t_token_type get_token_type(char *value)
{
	if (ft_strncmp(value, ">", ft_strlen(value)) == 0 ||
		ft_strncmp(value, ">>", ft_strlen(value)) == 0)
		return (REDIR_OUT);
	if (ft_strncmp(value, "<", ft_strlen(value)) == 0)
		return (REDIR_IN);
	return (WORD);
}

int set_token_redir(t_prompt **prompt, char *value, char *input)
{
	int len;
	char *next_value;
	t_token_type token;

	len = next_value_len(input);
	next_value = ft_substr(input, 0, len);
	token = get_token_type(value);
	if (token == REDIR_IN)
		prompt_add_redir_in(*prompt, un_quote(next_value, TRUE));
	else if (token == REDIR_OUT)
	{
		if (ft_strncmp(value, ">", ft_strlen(value)) == 0)
			prompt_add_redir_out(*prompt, un_quote(next_value, TRUE), RO_TRUNC);
		else if (ft_strncmp(value, ">>", ft_strlen(value)) == 0)
			prompt_add_redir_out(*prompt, un_quote(next_value, TRUE),
								 RO_APPEND);
	}
	return (len);
}

int set_prompt_token(t_prompt **prompt, char *value, char *input)
{
	int len;
	t_token_type token;

	len = 0;
	token = get_token_type(value);
	if (token == WORD)
	{
		if (!((*prompt)->cmd))
			prompt_create_cmd(*prompt, un_quote(value, FALSE));
		else
			prompt_add_cmd_arg(*prompt, un_quote(value, FALSE));
	}
	else if (token == REDIR_IN || token == REDIR_OUT)
		len += set_token_redir(prompt, value, input);
	return (len);
}
