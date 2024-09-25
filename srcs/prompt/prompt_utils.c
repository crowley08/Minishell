/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:15 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 00:13:49 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*trim_ext_space(char *input)
{
	char	*str;
	int		end;
	int		start;

	end = ft_strlen(input) - 1;
	if (!end)
		return (NULL);
	start = 0;
	while (start < end && ft_isspace(input[start]))
		start++;
	while (start > end && ft_isspace(input[end]))
		end--;
	if (start >= end)
		return (NULL);
	str = ft_substr(input, start, (end - start));
	free(input);
	return (str);
}
