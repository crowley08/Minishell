/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tokenizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:54:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 11:47:33 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_type	get_token_type(char *value)
{
	if (ft_strncmp(value, ">", ft_strlen(value)) == 0 || ft_strncmp(value, ">>",
			ft_strlen(value)) == 0)
		return (REDIR_OUT);
	if (ft_strncmp(value, "<", ft_strlen(value)) == 0)
		return (REDIR_IN);
	return (WORD);
}

int	set_token_redir(t_prompt **prompt, char *value, t_token_type type,
		char *input)
{
	int		len;
	char	*next_value;

	len = next_value_len(input);
	next_value = ft_substr(input, 0, len);
	type = get_token_type(value);
	if (type == REDIR_IN)
		prompt_add_redir_in(*prompt, un_quote(next_value, TRUE));
	else if (type == REDIR_OUT)
	{
		if (ft_strncmp(value, ">", ft_strlen(value)) == 0)
			prompt_add_redir_out(*prompt, un_quote(next_value, TRUE), RO_TRUNC);
		else if (ft_strncmp(value, ">>", ft_strlen(value)) == 0)
			prompt_add_redir_out(*prompt, un_quote(next_value, TRUE),
				RO_APPEND);
	}
	return (len);
}

int	set_prompt_token(t_prompt **prompt, char *value, char *input)
{
	int				len;
	t_token_type	type;

	len = 0;
	type = get_token_type(value);
	if (type == WORD)
	{
		if (!((*prompt)->cmd))
			prompt_create_cmd(*prompt, un_quote(value, FALSE));
		else
			prompt_add_cmd_arg(*prompt, un_quote(value, FALSE));
	}
	else if (type == REDIR_IN || type == REDIR_OUT)
		len += set_token_redir(prompt, value, type, input);
	return (len);
}
