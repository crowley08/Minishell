/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:56:05 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:56:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_tab_str(char **tab_str)
{
	int	i;

	i = 0;
	if (!tab_str)
		return (NULL);
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
	return (NULL);
}
