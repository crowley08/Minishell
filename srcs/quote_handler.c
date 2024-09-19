/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:57:36 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 14:04:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	quote_update_state(char c, t_quote_state *d_q, t_quote_state *s_q)
{
	if (*d_q == CLOSED && *s_q == CLOSED)
	{
		if (c == '"')
			*d_q = OPENED;
		else if (c == '\'')
			*s_q = OPENED;
	}
	else if (*d_q == OPENED || *s_q == OPENED)
	{
		if (c == '"')
			*d_q = CLOSED;
		else if (c == '\'')
			*s_q = CLOSED;
	}
}

t_bool	quote_opened(char *prompt)
{
	t_quote_state	d_q;
	t_quote_state	s_q;
	int				i;

	i = 0;
	d_q = CLOSED;
	s_q = CLOSED;
	while (prompt[i])
	{
		if (ms_is_quote(prompt[i]))
			quote_update_state(prompt[i], &d_q, &s_q);
		i++;
	}
	if (d_q == OPENED || s_q == OPENED)
		return (TRUE);
	return (FALSE);
}
