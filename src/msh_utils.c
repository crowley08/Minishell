/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:09 by saandria          #+#    #+#             */
/*   Updated: 2024/09/26 11:04:34 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_minishell(t_msh *msh)
{
	free_spl(msh->envc);
	free_tokens(&msh->token);
	free_env(&msh->envp);
	free(msh->input);
}
