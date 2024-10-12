/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_syntax_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:02:42 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 13:51:23 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
t_bool has_pipe_start_end(char *input)
{
	int i_start;
	int i_end;

	i_start = 0;
	i_end = ft_strlen(input) - 1;
	while (i_start < i_end && ft_isspace(input[i_start]))
		i_start++;
	while (i_start < i_end && ft_isspace(input[i_end]))
		i_end--;
	if (input[i_start] == '|' || input[i_end] == '|')
		return (TRUE);
	return (FALSE);
}
t_bool has_quote_opened(char *input)
{
	t_quote_dt quote;

	init_quote(&quote);
	while (*input)
	{
		if (is_quote(*input))
			update_quote(*input, &quote);
		input++;
	}
	if (quote_opened(quote))
		return (TRUE);
	return (FALSE);
}

t_bool has_pipe_succ(char *input)
{
	int i_pipe;
	t_quote_dt quote;

	init_quote(&quote);
	while (input && *input)
	{
		update_quote(*input, &quote);
		if (*input == '|' && quote_closed(quote))
		{
			i_pipe = 1;
			while (*(input + i_pipe) && ft_isspace(*(input + i_pipe)))
				i_pipe++;
			if (*(input + i_pipe) == '|')
				return (TRUE);
			input += i_pipe + 1;
		}
		input++;
	}
	return (FALSE);
}
t_bool has_redir_invalid(char *input)
{
	t_quote_dt quote;
	t_bool valid;

	init_quote(&quote);
	while (input && *input && *(input + 1))
	{
		update_quote(*input, &quote);
		if (quote_closed(quote) && is_redir(*input))
		{
			valid = is_redir_valid(&input);
			if (!valid)
				return (TRUE);
		}
		else
			input++;
	}
	return (FALSE);
}

int launch_syntax_validation(char *input)
{
	t_error_stt error;
	error = NOTHING;
	while (42)
	{
		if (has_quote_opened(input) && set_syntax_error(&error, STX_QUOTE))
			break;
		if (has_pipe_start_end(input) && set_syntax_error(&error,
														  STX_PIPE_START_END))
			break;
		if (has_pipe_succ(input) && set_syntax_error(&error,
													 STX_PIPE_SUCC))
			break;
		if (has_redir_invalid(input) && set_syntax_error(&error, STX_REDIR))
			break;
		break;
	}
	if (error == NOTHING)
		return (EXIT_SUCCESS);
	print_syntax_error(error);
	return (EXIT_FAILURE);
}
