/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:58:10 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 14:38:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_bool	ms_is_quote(char c)
{
	return (c == '"' || c == '\'');
}

t_bool	ms_is_var_char(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95);
}

void	quote_init_state(t_quote_state *d_q, t_quote_state *s_q)
{
	*d_q = CLOSED;
	*s_q = CLOSED;
}
