/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:36:45 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/10 07:35:47 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_next_word_len(char *input)
{
	t_quote_dt	quote;
	int			len;

	init_quote_dt(&quote);
	len = 0;
	if (is_char_redir(input[len]))
	{
		len++;
		if (is_char_redir(input[len]))
			len++;
		return (len);
	}
	while (input && input[len])
	{
		update_quote_dt(input[len], &quote);
		// if (quote.d_q == OPENED || quote.s_q == OPENED
		// || ft_isalnum(input[len])
		// 	|| input[len] == '_' || is_quote(input[len]) || input[len] == '.')
		// 	len++;
		// else
		// 	break ;
		if (quote.d_q == CLOSED && quote.s_q == CLOSED
			&& (ft_isspace(input[len]) || is_char_redir(input[len])))
			break ;
		len++;
	}
	return (len);
}

int	fill_token_redir_out(t_prompt **prompt, char *value, char *input)
{
	int				len;
	char			*next_value;
	t_token_type	type;

	len = get_next_word_len(input);
	next_value = ft_substr(input, 0, len);
	type = get_token_type(value);
	if (type == REDIR_IN)
		prompt_add_file_redir_in(*prompt, get_new_input_unquote(next_value,
				TRUE));
	else if (type == REDIR_OUT)
	{
		if ((ft_strncmp(value, ">", ft_strlen(value)) == 0))
			prompt_add_file_redir_out(*prompt, get_new_input_unquote(next_value,
					TRUE), REDIR_TRUNC);
		else if ((ft_strncmp(value, ">>", ft_strlen(value)) == 0))
			prompt_add_file_redir_out(*prompt, get_new_input_unquote(next_value,
					TRUE), REDIR_APPEND);
	}
	return (len);
}

int	fill_prompt_token(t_prompt **prompt, char *value, char *input)
{
	int				len;
	t_token_type	type;

	len = 0;
	type = get_token_type(value);
	if (type == WORD)
	{
		if (!((*prompt)->cmd))
			prompt_create_cmd(*prompt, get_new_input_unquote(value, FALSE));
		else
			prompt_add_cmd_arg(*prompt, get_new_input_unquote(value, FALSE));
	}
	else if (type == REDIR_IN || type == REDIR_OUT)
		len = fill_token_redir_out(prompt, value, input);
	return (len);
}
