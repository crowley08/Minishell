/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:13:07 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:50:33 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*set_filename(int i)
{
	char	*index;
	char	*filename;

	index = ft_itoa(i);
	filename = ft_strjoin(".mhs_", index);
	free(index);
	return (filename);
}

int	get_eof_len(char *input)
{
	int			len;
	t_quote_dt	quote;

	len = 0;
	init_quote(&quote);
	while (input && input[len] && !is_redir(input[len])
		&& !ft_isspace(input[len]) && input[len] != '|')
	{
		update_quote(input[len], &quote);
		len++;
		while (quote_opened(quote))
		{
			update_quote(input[len], &quote);
			len++;
		}
	}
	return (len);
}
