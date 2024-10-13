/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:39:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:55:53 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

void	init_quote(t_quote_dt *quote)
{
	quote->d_q = CLOSED;
	quote->s_q = CLOSED;
}

t_bool	quote_opened(t_quote_dt quote)
{
	return (quote.d_q == OPENED || quote.s_q == OPENED);
}

t_bool	quote_closed(t_quote_dt quote)
{
	return (quote.d_q == CLOSED && quote.s_q == CLOSED);
}

void	update_quote(char c, t_quote_dt *quote)
{
	if (quote_closed(*quote))
	{
		if (c == '\"')
			quote->d_q = OPENED;
		else if (c == '\'')
			quote->s_q = OPENED;
	}
	else if (quote_opened(*quote))
	{
		if (c == '\"')
			quote->d_q = CLOSED;
		else if (c == '\'')
			quote->s_q = CLOSED;
	}
}
