/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:41:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 08:33:52 by arakotom         ###   ########.fr       */
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
	data->curr_error = NOTHING;
}

void	free_data(t_data *data)
{
	if (data->envp)
		free_env_list(&(data->envp));
	if (data->input)
		free(data->input);
	if (data->prompt)
		free_prompt_list(&(data->prompt));
}

void	reset_data(t_data *data)
{
	if (data->input)
		free(data->input);
	if (data->prompt)
		free_prompt_list(&(data->prompt));
	data->input = NULL;
	data->prompt = NULL;
	data->curr_error = NOTHING;
}
