/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:33:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 17:05:59 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_trim(char *prompt)
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
	return (str);
}
