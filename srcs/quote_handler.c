/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:14 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 16:34:11 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_quote(char c, t_quote_state *d_q, t_quote_state *s_q)
{
	if ((c == '"' || c == '\'') && (*d_q == closed) && (*s_q == closed))
	{
		if (c == '"')
			*d_q = opened;
		else if (c == '\'')
			*s_q = opened;
	}
	else if ((c == '"' || c == '\'') && (*d_q == opened || *s_q == opened))
	{
		if (c == '"')
			*d_q = closed;
		else if (c == '\'')
			*s_q = closed;
	}
}

t_bool	is_quote_opened(char *input)
{
	t_quote_state	d_q;
	t_quote_state	s_q;
	int				i;

	i = 0;
	d_q = closed;
	s_q = closed;
	while (input[i])
	{
		update_quote(input[i], &d_q, &s_q);
		i++;
	}
	if (d_q == opened || s_q == opened)
		return (true);
	return (false);
}
