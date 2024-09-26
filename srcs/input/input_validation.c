/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:52:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 12:13:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_empty(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	is_pipe_start_end(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end && ft_isspace(str[start]))
		start++;
	while (start < end && ft_isspace(str[end]))
		end--;
	if (str[start] == '|' || str[end] == '|')
		return (TRUE);
	return (FALSE);
}

t_bool	is_quote_opened(char *str)
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

t_bool	is_have_dbl_pipe_succ(char *str)
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

t_bool	input_valid(t_data *data)
{
	while (42)
	{
		if (is_quote_opened(data->input) && set_input_error(&(data->curr_error),
				STX_QUOTE))
			break ;
		if (is_pipe_start_end(data->input)
			&& set_input_error(&(data->curr_error), STX_PIPE_START_END))
			break ;
		if (is_have_dbl_pipe_succ(data->input)
			&& set_input_error(&(data->curr_error), STX_PIPE_DBL_SUCC))
			break ;
		break ;
	}
	if (data->curr_error != NOTHING)
		return (FALSE);
	return (TRUE);
}
