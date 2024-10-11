/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:14:41 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:15:11 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_char_redir(char c)
{
	return (c == '<' || c == '>');
}

t_bool	is_redir_valid(char **str)
{
	if (is_char_redir(*(*str + 1)))
	{
		if (*(*str + 1) == **str)
			*str += 1;
		else
			return (T);
	}
	*str += 1;
	while (*str && ft_isspace(**str))
		(*str)++;
	if (is_char_redir(**str) || **str == '|')
		return (F);
	return (T);
}
