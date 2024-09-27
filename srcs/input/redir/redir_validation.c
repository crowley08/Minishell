/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:32:24 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/27 15:32:32 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool is_redir_wrong(char **str)
{
	if (is_char_redir(*(*str + 1)))
	{
		if (*(*str + 1) == **str)
			*str += 1;
		else
			return (TRUE);
	}
	*str += 1;
	while (*str && ft_isspace(**str))
		(*str)++;
	if (is_char_redir(**str) || **str == '|')
		return (TRUE);
	return (FALSE);
}

t_bool is_some_redir_invalid(char *str)
{
	t_quote_dt quote;
	t_bool wrong;

	init_quote_dt(&quote);
	while (str && *str && *(str + 1))
	{
		update_quote_dt(*str, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && is_char_redir(*str))
		{
			wrong = is_redir_wrong(&str);
			if (wrong)
				return (TRUE);
		}
		else
			str++;
	}
	return (FALSE);
}
