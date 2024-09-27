/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:07:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/27 14:56:27 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_input(void)
{
	char *input;

	// input = readline("minishell > ");
	input = ft_strdup("<file cat ><file_name");
	while (is_empty(input))
	{
		free(input);
		input = readline("minishell > ");
	}
	return (input);
}
