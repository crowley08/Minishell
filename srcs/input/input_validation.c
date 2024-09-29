/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:52:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 12:21:40 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		return (TRUE);
	return (FALSE);
}

t_bool	has_quote_opened(char *str)
{
	t_quote_dt	quote;

	init_quote_dt(&quote);
	while (*str)
	{
		if (is_quote(*str))
			update_quote_dt(*str, &quote);
		str++;
	}
	if (quote.d_q == OPENED || quote.s_q == OPENED)
		return (TRUE);
	return (FALSE);
}

t_bool	has_dbl_pipe_succ(char *str)
{
	int			next_pipe;
	t_quote_dt	quote;

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
				return (TRUE);
			str += next_pipe + 1;
		}
		str++;
	}
	return (FALSE);
}

t_bool	has_syntax_error(char *line, t_error_stt *error)
{
	while (42)
	{
		if (has_quote_opened(line) && set_syntax_error(error, STX_QUOTE))
			break ;
		if (has_pipe_start_end_redir(line) && set_syntax_error(error,
				STX_PIPE_START_END))
			break ;
		if (has_dbl_pipe_succ(line) && set_syntax_error(error,
				STX_PIPE_DBL_SUCC))
			break ;
		if (has_some_redir_invalid(line) && set_syntax_error(error, STX_REDIR))
			break ;
		break ;
	}
	if (*error != NOTHING)
		return (TRUE);
	return (FALSE);
}
