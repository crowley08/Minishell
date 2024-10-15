/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:07:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 19:28:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	set_exit_status_parse_token(t_msh *msh)
{
	msh->exit_status = EXIT_FAILURE;
	free_msh_reset(msh);
	return (TRUE);
}

t_bool	has_parse_token_prompt_error(t_msh *msh)
{
	char	**tab;

	tab = split_pipe(msh->input);
	if (!tab)
		return (set_exit_status_parse_token(msh));
	msh->prompt_list = parse_prompt(tab);
	ft_free_tab_str(tab);
	if (!(msh->prompt_list))
		return (set_exit_status_parse_token(msh));
	return (FALSE);
}
