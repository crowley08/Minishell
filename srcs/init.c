/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:41:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/25 19:43:22 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	data->envp = NULL;
	data->input = NULL;
	data->prompt = NULL;
}
