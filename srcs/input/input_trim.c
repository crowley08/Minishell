/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:15 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/02 11:56:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_trimmed(char *str)
{
	int	end;

	end = ft_strlen(str) - 1;
	if (!end)
		return (FALSE);
	if (!ft_isspace(str[0]) || !ft_isspace(str[end]))
		return (FALSE);
	while (str && *str)
	{
		if (ft_isspace(*str) && ft_isspace(*(str + 1)))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

char	*trim_space_out(char *input)
{
	char	*str;
	int		end;
	int		start;

	end = ft_strlen(input);
	if (!end)
		return (NULL);
	start = 0;
	while (start < end - 1 && ft_isspace(input[start]))
		start++;
	while (start < end - 1 && ft_isspace(input[end - 1]))
		end--;
	if (start >= end)
		return (NULL);
	str = ft_substr(input, start, (end - start));
	return (str);
}

int	str_trim_in_len(char *str)
{
	int			len;
	t_quote_dt	quote;

	len = 0;
	init_quote_dt(&quote);
	while (str && *str)
	{
		update_quote_dt(*str, &quote);
		if (ft_isspace(*str) && ft_isspace(*(str + 1)))
		{
			if ((quote.d_q == OPENED || quote.s_q == OPENED))
				len++;
		}
		else
			len++;
		str++;
	}
	return (len);
}

char	*trim_space_in(char *input)
{
	char		*str;
	t_quote_dt	quote;
	int			i;
	int			j;

	i = 0;
	j = -1;
	init_quote_dt(&quote);
	str = (char *)malloc(sizeof(char) * str_trim_in_len(input) + 1);
	if (!str)
		return (NULL);
	while (input && input[++j])
	{
		update_quote_dt(input[j], &quote);
		if (!ft_isspace(input[j]) || !ft_isspace(input[j + 1]))
			str[i++] = input[j];
		else if (quote.d_q == OPENED || quote.s_q == OPENED)
			str[i++] = input[j];
		str[i] = '\0';
	}
	return (str);
}

char	*trim_space_all(char *input)
{
	char	*str_out;
	char	*str_in;

	if (!input)
		return (NULL);
	str_out = trim_space_out(input);
	if (!str_out)
		return (NULL);
	str_in = trim_space_in(str_out);
	free(str_out);
	if (!str_in)
		return (NULL);
	return (str_in);
}
