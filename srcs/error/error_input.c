/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:17:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 12:19:01 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void error_syntax(t_msh *msh, char *input)
{
	perror("msh: syntax error");
	free(input);
	free_msh(msh);
	exit(EXIT_FAILURE);
}
