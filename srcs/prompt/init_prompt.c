/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:07:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 07:54:51 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void test_split_pipe(char *input)
{
	char **tab;

	tab = split_pipe(input);
	if (!tab)
		ft_printf("Error: Cannot split pipe");
	else
	{
		print_prompt_splitted(tab);
		ft_free_tab_str(tab);
	}
}
