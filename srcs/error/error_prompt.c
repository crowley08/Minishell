/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:10:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 11:22:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
void error_prompt_split(t_msh *msh)
{
	perror("msh: split prompt error");
	free_msh_reset(msh);
}

void error_prompt_token(t_msh *msh)
{
	perror("msh: token prompt error");
    free_msh_reset(msh);
}
