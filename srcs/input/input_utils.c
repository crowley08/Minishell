/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:14:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 20:28:12 by arakotom         ###   ########.fr       */
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
