/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:28:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:44:36 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_dup_env(t_msh *msh)
{
	perror("msh: error , duplicate envp failed");
	free_msh(msh);
	exit(EXIT_FAILURE);
}
