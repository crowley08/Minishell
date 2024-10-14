/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:07:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 13:00:11 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//! FIXME: delete this function after creation_prompt si done
void test_split_pipe(char *input)
{
	char **tab;

	tab = split_pipe(input);
	if (!tab)
		printf("Error: Cannot split pipe");
	else
	{
		print_prompt_splitted(tab);
		ft_free_tab_str(tab);
	}
}

t_bool set_exit_status_split(t_msh *msh)
{
	msh->exit_status = EXIT_SUCCESS;
	error_prompt_split(msh);
	return (TRUE);
}

t_bool set_exit_status_token(t_msh *msh)
{
	msh->exit_status = EXIT_SUCCESS;
	error_prompt_token(msh);
	return (TRUE);
}

t_bool has_parse_token_prompt_error(t_msh *msh)
{
	char **tab;

	tab = split_pipe(msh->input);
	if (!tab)
		return (set_exit_status_split(msh));
	msh->prompt_list = parse_prompt(tab);
	ft_free_tab_str(tab);
	if (!(msh->prompt_list))
		return (set_exit_status_token(msh));
	return (FALSE);
}
