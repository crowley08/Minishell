/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:14:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:15:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_empty_line(char *line)
{
	while (line && *line)
	{
		if (!ft_isspace(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}
