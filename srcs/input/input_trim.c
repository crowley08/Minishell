/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:51:13 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:53:27 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_trimmed(char *line)
{
	int	i_end;

	i_end = ft_strlen(line) - 1;
	if (i_end < 0)
		return (FALSE);
	if (ft_isspace(line[0]) || ft_isspace(line[i_end]))
		return (FALSE);
	while (line && *line)
	{
		if (ft_isspace(*line) && ft_isspace(*(line + 1)))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

char	*trim_space_out(char *line)
{
	char	*new_line;
	int		i_end;
	int		i_start;

	i_end = ft_strlen(line) - 1;
	if (i_end < 0)
		return (NULL);
	i_start = 0;
	while (i_start < i_end && ft_isspace(line[i_start]))
		i_start++;
	while (i_start < i_end && ft_isspace(line[i_end]))
		i_end--;
	if (i_start > i_end)
		return (NULL);
	new_line = ft_substr(line, i_start, (i_end + 1 - i_start));
	return (new_line);
}

int	trim_in_len(char *line)
{
	int		len;
	t_quote	quote;

	len = 0;
	init_quote(&quote);
	while (line && *line)
	{
		update_quote(*line, &quote);
		if (ft_isspace(*line) && ft_isspace(*(line + 1)))
		{
			if (quote_opened(quote))
				len++;
		}
		else
			len++;
		line++;
	}
	return (len);
}

char	*trim_space_in(char *line)
{
	char	*new_line;
	t_quote	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_quote(&quote);
	new_line = (char *)malloc(sizeof(char) * trim_in_len(line) + 1);
	if (!new_line)
		return (NULL);
	while (line && line[j])
	{
		update_quote(line[j], &quote);
		if (!ft_isspace(line[j]) || !ft_isspace(line[j + 1]))
			new_line[i++] = line[j];
		else if (quote_opened(quote))
			new_line[i++] = line[j];
		new_line[i] = '\0';
		j++;
	}
	return (new_line);
}

char	*trim_space_all(char *line)
{
	char	*line_tmp;
	char	*new_line;

	if (!line)
		return (NULL);
	line_tmp = trim_space_out(line);
	if (!line_tmp)
		return (NULL);
	new_line = trim_space_in(line_tmp);
	free(line_tmp);
	if (!new_line)
		return (NULL);
	return (new_line);
}
