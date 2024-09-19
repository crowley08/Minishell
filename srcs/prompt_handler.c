/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:33:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 23:37:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ms_strlen_formate(char *prompt)
{
	t_quote_state	d_q;
	t_quote_state	s_q;
	int				len;

	len = 0;
	quote_init_state(&d_q, &s_q);
	while (*prompt)
	{
		quote_update_state(*prompt, &d_q, &s_q);
		if (ft_isspace(*prompt) && ft_isspace(*(prompt + 1)))
		{
			if ((d_q == OPENED || s_q == OPENED))
				len++;
		}
		else
			len++;
		prompt++;
	}
	return (len);
}

char	*ms_trim_free(char *prompt)
{
	char	*str;
	int		p_len;
	int		i;

	p_len = ft_strlen(prompt) - 1;
	if (!p_len)
		return (NULL);
	i = 0;
	while ((ft_isspace(prompt[i]) || ft_isspace(prompt[p_len])) && i < p_len)
	{
		if (ft_isspace(prompt[i]))
			i++;
		if (ft_isspace(prompt[p_len]))
			p_len--;
	}
	str = ft_substr(prompt, i, p_len - i + 1);
	free(prompt);
	return (str);
}
// prompt must already trimmed, use [*ms_trim_free(char *)]
void	format_data_prompt(char **str, char *prompt)
{
	t_quote_state	d_q;
	t_quote_state	s_q;
	int				i;
	int				j;

	j = 0;
	i = 0;
	quote_init_state(&d_q, &s_q);
	*str = (char *)malloc(sizeof(char) * ms_strlen_formate(prompt) + 1);
	if (!(*str))
		return (free(prompt));
	while (prompt[j])
	{
		quote_update_state(prompt[j], &d_q, &s_q);
		if (ft_isspace(prompt[j]) && ft_isspace(prompt[j + 1]))
		{
			if ((d_q == OPENED || s_q == OPENED))
				(*str)[i++] = prompt[j];
		}
		else
			(*str)[i++] = prompt[j];
		j++;
	}
	(*str)[i] = '\0';
	free(prompt);
}
