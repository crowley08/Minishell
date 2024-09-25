/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:07:22 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 01:03:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

void	init_quote_dt(t_quote_dt *quote)
{
	quote->d_q = CLOSED;
	quote->s_q = CLOSED;
}

void	update_quote_dt(char c, t_quote_dt *quote)
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
