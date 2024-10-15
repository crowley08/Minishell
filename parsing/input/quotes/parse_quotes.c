/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:59:26 by saandria          #+#    #+#             */
/*   Updated: 2024/10/15 15:46:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	init_quote(t_quote *quote)
{
	quote->d_q = CLOSED;
	quote->s_q = CLOSED;
}

void	update_quote(char c, t_quote *quote)
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

char	*un_quote(char *str, t_bool do_free)
{
	t_quote	quote;
	int		i;
	char	*res;
	char	*tmp_c;

	res = NULL;
	i = 0;
	init_quote(&quote);
	while (str && str[i])
	{
		if (is_quote(str[i]) && quote_closed(quote))
			update_quote(str[i++], &quote);
		update_quote(str[i], &quote);
		if (is_quote(str[i]) && quote_closed(quote))
			update_quote(str[++i], &quote);
		else if (str[i])
		{
			tmp_c = ft_substr(str + i++, 0, 1);
			res = msh_strjoin(res, tmp_c);
			free(tmp_c);
		}
	}
	if (do_free)
		free(str);
	return (res);
}
