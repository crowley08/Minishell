/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:21:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/20 00:20:33 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_count_prompt(char *str)
{
	int				count;
	t_quote_data	q_data;

	count = 0;
	quote_init_state(&q_data);
	while (*str)
	{
		count++;
		while (*str && (*str != '|' || (q_data.d_q == OPENED
					|| q_data.s_q == OPENED)))
			quote_update_state(*(str++), &q_data);
		if (*str)
			str++;
	}
	return (count);
}
