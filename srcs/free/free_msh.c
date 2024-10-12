/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:30:12 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 12:36:28 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_msh(t_msh *msh)
{
	if (msh->env_list)
		free_env_list(&(msh->env_list));
}

void free_msh_syntax(t_msh *msh, char *input)
{
	free(input);
	free_msh(msh);
}
