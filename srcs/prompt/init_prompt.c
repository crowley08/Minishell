/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:07:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:03:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	set_exit_status_split(t_msh *msh)
{
	msh->exit_status = EXIT_FAILURE;
	error_prompt_split(msh);
	return (TRUE);
}

t_bool	set_exit_status_token(t_msh *msh)
{
	msh->exit_status = EXIT_FAILURE;
	error_prompt_token(msh);
	return (TRUE);
}

t_bool	has_parse_token_prompt_error(t_msh *msh)
{
	char	**tab;

	tab = split_pipe(msh->input);
	if (!tab)
		return (set_exit_status_split(msh));
	msh->prompt_list = parse_prompt(tab);
	ft_free_tab_str(tab);
	if (!(msh->prompt_list))
		return (set_exit_status_token(msh));
	return (FALSE);
}
