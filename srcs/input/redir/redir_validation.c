/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:32:24 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/27 13:47:23 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_bool is_redir_wrong(char *str, t_bool (*redir_correct)(char **))
{
	t_quote_dt quote;
	t_bool wrong;

	init_quote_dt(&quote);
	while (str && *str && *(str + 1))
	{
		update_quote_dt(*str, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && is_char_redir(*str))
		{
			wrong = redir_correct(&str);
			if (wrong)
				return (TRUE);
		}
		else
			str++;
	}
	return (FALSE);
}

t_bool is_redir_out_wrong(char **str)
{
	if (**str == '>' && !is_char_redir(*(*str + 1)))
	{
		*str += 1;
		while (*str && ft_isspace(**str))
			(*str)++;
		if (is_char_redir(**str) || **str == '|')
			return (TRUE);
	}
	else
		(*str)++;
	ft_printf("Eto zao tsika: $%s$\n", *str);
	return (FALSE);
}

t_bool is_some_redir_invalid(char *str)
{
	return (is_redir_wrong(str, &is_redir_out_wrong));
}
