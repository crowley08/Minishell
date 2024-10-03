/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:15 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/02 11:59:24 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_prompts(char **prompts)
{
	if (prompts)
		ft_printf("Prompts:\n");
	while (prompts && *prompts)
	{
		ft_printf("$%s$\n", *prompts);
		prompts++;
	}
}
