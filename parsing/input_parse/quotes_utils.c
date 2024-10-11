/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:12:53 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:14:21 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

void	init_quote_dt(t_quote_type *quote)
{
	quote->d_q = CLOSED;
	quote->s_q = CLOSED;
}

void	update_quote_dt(char c, t_quote_type *quote)
{
	if (quote->d_q == CLOSED && quote->s_q == CLOSED)
	{
		if (c == '\"')
			quote->d_q = OPENED;
		else if (c == '\'')
			quote->s_q = OPENED;
	}
	else if (quote->d_q == OPENED || quote->s_q == OPENED)
	{
		if (c == '\"')
			quote->d_q = CLOSED;
		else if (c == '\'')
			quote->s_q = CLOSED;
	}
}
