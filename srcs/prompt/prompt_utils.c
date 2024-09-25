/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:15 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 01:41:13 by arakotom         ###   ########.fr       */
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
	return (TRUE);
}
