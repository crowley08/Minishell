/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:32 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:52:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_redir(char c)
{
	return (c == '<' || c == '>');
}

t_bool	is_redir_valid(char **input)
{
	if (is_redir(*(*input + 1)))
	{
		if (*(*input + 1) == **input)
			*input += 1;
		else
			return (F);
	}
	*input += 1;
	while (*input && ft_isspace(**input))
		(*input)++;
	if (**input == '\0' || is_redir(**input) || **input == '|')
		return (F);
	return (T);
}

t_bool	has_redir_invalid(char *input)
{
	t_quote	quote;
	t_bool	valid;

	init_quote(&quote);
	while (input && *input)
	{
		update_quote(*input, &quote);
		if (quote_closed(quote) && is_redir(*input))
		{
			valid = is_redir_valid(&input);
			if (!valid)
				return (T);
		}
		else
			input++;
	}
	return (F);
}
