/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:49:10 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 11:35:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool set_syntax_error(t_error_stt *curr_error, t_error_stt error)
{
	*curr_error = error;
	return (TRUE);
}

t_bool is_empty_line(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool is_char_redir(char c)
{
	return (c == '<' || c == '>');
}
