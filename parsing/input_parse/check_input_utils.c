/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:10:02 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:38:04 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	has_some_redir_invalid(char *str)
{
	t_quote_type	quote;
	t_bool			valid;

	init_quote_dt(&quote);
	while (str && *str && *(str + 1))
	{
		update_quote_dt(*str, &quote);
		if (quote.d_q == CLOSED && quote.s_q == CLOSED && is_char_redir(*str))
		{
			valid = is_redir_valid(&str);
			if (!valid)
				return (T);
		}
		else
			str++;
	}
	return (F);
}

t_bool	has_dbl_pipe_succ(char *str)
{
	int				next_pipe;
	t_quote_type	quote;

	init_quote_dt(&quote);
	while (str && *str)
	{
		update_quote_dt(*str, &quote);
		if (*str == '|' && quote.d_q == CLOSED && quote.s_q == CLOSED)
		{
			next_pipe = 1;
			while (*(str + next_pipe) && ft_isspace(*(str + next_pipe)))
				next_pipe++;
			if (*(str + next_pipe) == '|')
				return (T);
			str += next_pipe + 1;
		}
		str++;
	}
	return (F);
}

t_bool	has_pipe_start_end_redir(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end && ft_isspace(str[start]))
		start++;
	while (start < end && ft_isspace(str[end]))
		end--;
	if (str[start] == '|' || str[end] == '|' || is_char_redir(str[end]))
		return (T);
	return (F);
}

t_bool	has_quote_opened(char *str)
{
	t_quote_type	quote;

	init_quote_dt(&quote);
	while (*str)
	{
		if (is_quote(*str))
			update_quote_dt(*str, &quote);
		str++;
	}
	if (quote.d_q == OPENED || quote.s_q == OPENED)
		return (T);
	return (F);
}
