/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:07:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 14:29:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_input(void)
{
	char *input;

	// input = readline("minishell > ");
	input = ft_strdup("cat              file|< file1 ls|          << eof cat>file");
	while (is_empty(input))
	{
		free(input);
		input = readline("minishell > ");
	}
	return (input);
}
