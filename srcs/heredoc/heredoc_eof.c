/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_eof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:47:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 17:02:47 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *msh_strjoin(char *s1, char *s2)
{
	char *res;
	int i;
	int j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		ft_strlcpy(res, s1, i + 1);
	if (s2)
		ft_strlcat(res, s2, i + j + 1);
	free(s1);
	return (res);
}

char *un_quote(char *str, t_bool do_free)
{
	t_quote_dt quote;
	int i;
	char *res;
	char *tmp_c;

	res = NULL;
	i = 0;
	init_quote(&quote);
	while (str && str[i])
	{
		if (is_quote(str[i]) && quote_closed(quote))
			update_quote(str[i++], &quote);
		update_quote(str[i], &quote);
		if (is_quote(str[i]) && quote_closed(quote))
			update_quote(str[i++], &quote);
		if (str[i])
		{
			tmp_c = ft_substr(&str[i++], 0, 1);
			res = msh_strjoin(tmp_c, tmp_c);
			free(tmp_c);
		}
	}
	if (do_free)
		free(str);
	return (res);
}
t_bool has_to_expand_heredoc(char *eof_input)
{
	int i;

	i = 0;
	while (eof_input[i])
	{
		if (is_quote(eof_input[i]))
		{
			free(eof_input);
			return (FALSE);
		}
	}
	free(eof_input);
	return (TRUE);
}
