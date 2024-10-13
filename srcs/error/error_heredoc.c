/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:47:18 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 20:01:09 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_heredoc(t_msh *msh, char *input)
{
	perror("msh: heredoc error");
	free(input);
	free_msh_reset(msh);
}

t_bool	set_heredoc_error(t_error_stt *error, t_error_stt type)
{
	*error = type;
	return (TRUE);
}
