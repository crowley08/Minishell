/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:29:54 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:21:52 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_empty_str(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (FALSE);
		str++;
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
