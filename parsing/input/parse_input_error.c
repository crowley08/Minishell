/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:17 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:51:04 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	has_pipe_start_end(char *input)
{
	int	i_start;
	int	i_end;

	i_start = 0;
	i_end = ft_strlen(input) - 1;
	while (i_start < i_end && ft_isspace(input[i_start]))
		i_start++;
	while (i_start < i_end && ft_isspace(input[i_end]))
		i_end--;
	if (input[i_start] == '|' || input[i_end] == '|')
		return (T);
	return (F);
}

t_bool	has_pipe_succ(char *input)
{
	int		i_pipe;
	t_quote	quote;

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
				return (T);
			input += i_pipe + 1;
		}
		input++;
	}
	return (F);
}

void	print_syntax_error(t_error error)
{
	if (error == STX_PIPE_START_END)
		perror("msh: syntax error near unexpected token `|'");
	else if (error == STX_QUOTE)
		perror("msh: syntax error near unclosed token \" or '");
	else if (error == STX_PIPE_SUCC)
		perror("msh: syntax error near unexpected token `||'");
	else if (error == STX_REDIR)
		perror("msh: syntax error near unexpected token `newline'");
}

int	launch_syntax_validation(char *input)
{
	t_error	error;

	error = NOTHING;
	while (42)
	{
		if (has_quote_opened(input) && set_syntax_error(&error, STX_QUOTE))
			break ;
		if (has_pipe_start_end(input) && set_syntax_error(&error,
				STX_PIPE_START_END))
			break ;
		if (has_pipe_succ(input) && set_syntax_error(&error, STX_PIPE_SUCC))
			break ;
		if (has_redir_invalid(input) && set_syntax_error(&error, STX_REDIR))
			break ;
		break ;
	}
	if (error == NOTHING)
		return (EXIT_SUCCESS);
	print_syntax_error(error);
	return (EXIT_FAILURE);
}

void	error_fork_syntax(t_msh *msh, char *input)
{
	perror("Error: fork pid_syntax() returned");
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}
