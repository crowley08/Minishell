/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:14:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:19:05 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_empty_line(char *line)
{
	while (line && *line)
	{
		if (!ft_isspace(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

void	set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			msh->exit_status = 2;
			*has_error = TRUE;
		}
	}
	else if (WIFSIGNALED(status))
	{
		msh->exit_status = WTERMSIG(status);
		*has_error = TRUE;
	}
	else
	{
		msh->exit_status = 1;
		*has_error = TRUE;
	}
}

t_bool	is_redir(char c)
{
	return (c == '<' || c == '>');
}

t_bool	is_redir_valid(char **input)
{
	if (is_redir(*(*input + 1)))
	{
		if (*(*input + 1) == **input)
			*input += 1;
		else
			return (FALSE);
	}
	*input += 1;
	while (*input && ft_isspace(**input))
		(*input)++;
	if (**input == '\0' || is_redir(**input) || **input == '|')
		return (FALSE);
	return (TRUE);
}
