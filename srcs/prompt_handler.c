/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:33:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 23:29:57 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ms_strlen_formate(char *prompt)
{
	t_quote_data	q_data;
	int				len;

	len = 0;
	quote_init_state(&q_data);
	while (prompt && *prompt)
	{
		quote_update_state(*prompt, &q_data);
		if (ft_isspace(*prompt) && ft_isspace(*(prompt + 1)))
		{
			if ((q_data.d_q == OPENED || q_data.s_q == OPENED))
				len++;
		}
		else
			len++;
		prompt++;
	}
	return (len);
}
// elimination des espaces inutiles au debut et à la fin du prompt
char	*ms_trim_free(char *prompt)
{
	char	*str;
	int		p_len;
	int		i;

	p_len = ft_strlen(prompt);
	if (!p_len)
		return (NULL);
	i = 0;
	while (i < p_len - 1 && (ft_isspace(prompt[i]) || ft_isspace(prompt[p_len
				- 1])))
	{
		if (ft_isspace(prompt[i]))
			i++;
		if (ft_isspace(prompt[p_len - 1]))
			p_len--;
	}
	str = ft_substr(prompt, i, p_len - i);
	free(prompt);
	return (str);
}

char	*limit_prompt_free(char *input)
{
	char	*p_limited;
	int		limit;

	limit = 0;
	while (input && input[limit])
	{
		if (input[limit] == '|')
		{
			if (input[limit + 1] && input[limit + 1] == ' ')
			{
				if (input[limit + 2] && input[limit + 2] == '|')
					break ;
			}
			else if (input[limit + 1] && input[limit + 1] == '|')
				break ;
		}
		limit++;
	}
	if (input[limit - 1] == ' ')
		p_limited = ft_substr(input, 0, limit - 1);
	else
		p_limited = ft_substr(input, 0, limit);
	free(input);
	return (p_limited);
}
// prompt must already trimmed, use [*ms_trim_free(char *)]
// elimination des espaces inutiles dans le prompt
void	format_data_input(char **str, char *prompt)
{
	t_quote_data	q_data;
	int				i;
	int				j;

	j = 0;
	i = 0;
	quote_init_state(&q_data);
	*str = (char *)malloc(sizeof(char) * (ms_strlen_formate(prompt) + 1));
	if (!(*str))
		return (free(prompt));
	while (prompt && prompt[j])
	{
		quote_update_state(prompt[j], &q_data);
		if (ft_isspace(prompt[j]) && ft_isspace(prompt[j + 1]))
		{
			if ((q_data.d_q == OPENED || q_data.s_q == OPENED))
				(*str)[i++] = prompt[j];
		}
		else
			(*str)[i++] = prompt[j];
		j++;
	}
	(*str)[i] = '\0';
	free(prompt);
}
