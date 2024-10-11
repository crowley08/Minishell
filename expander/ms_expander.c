/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:09:01 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 13:40:14 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
t_token	*ms_expand(t_token **token)
{
	t_token	*expand;
	t_token	*new_expand;

	expand = expand_token(*token);
	*token = (*token)->next;
	while (*token)
	{
		new_expand = expand_token(*token);
		add_token(&expand, new_expand);
		*token = (*token)->next;
	}
	return (expand);
}
*/

