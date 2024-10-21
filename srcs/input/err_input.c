/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:29:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:21:44 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_stx(t_error_state error)
{
	if (error == STX_PIPE)
		ft_putstr_fd("msh: syntax error near unexpected token `|'.\n",
			STDERR_FILENO);
	else if (error == STX_QUOTE)
		ft_putstr_fd("msh: syntax error near unmatched quote \" or '.\n",
			STDERR_FILENO);
	else if (error == STX_REDIR)
		ft_putstr_fd("msh: syntax error near unexpected token 'newline'.\n",
			STDERR_FILENO);
}
