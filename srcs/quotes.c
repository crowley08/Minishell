/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:39:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:22:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

void	init_quote(t_quote *quote)
{
	quote->d_q = CLOSE;
	quote->s_q = CLOSE;
}

t_bool	quote_opened(t_quote quote)
{
	return (quote.d_q == OPEN || quote.s_q == OPEN);
}

t_bool	quote_closed(t_quote quote)
{
	return (quote.d_q == CLOSE && quote.s_q == CLOSE);
}

void	update_quote(char c, t_quote *quote)
{
	if (quote_closed(*quote))
	{
		if (c == '\"')
			quote->d_q = OPEN;
		else if (c == '\'')
			quote->s_q = OPEN;
	}
	else if (quote_opened(*quote))
	{
		if (c == '\"')
			quote->d_q = CLOSE;
		else if (c == '\'')
			quote->s_q = CLOSE;
	}
}
