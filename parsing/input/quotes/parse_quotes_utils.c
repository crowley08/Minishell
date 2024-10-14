/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:21:36 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:22:26 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool	quote_opened(t_quote quote)
{
	return (quote.d_q == OPENED || quote.s_q == OPENED);
}

t_bool	quote_closed(t_quote quote)
{
	return (quote.d_q == CLOSED && quote.s_q == CLOSED);
}

t_bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

t_bool	has_quote_opened(char *input)
{
	t_quote	quote;

	init_quote(&quote);
	while (*input)
	{
		if (is_quote(*input))
			update_quote(*input, &quote);
		input++;
	}
	if (quote_opened(quote))
		return (T);
	return (F);
}
