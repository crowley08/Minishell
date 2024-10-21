/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:29:53 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:56:43 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_hdc(t_error_state error)
{
	if (error == HDC_FD)
		perror("msh: ");
	else if (error == HDC_CTRL_C)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	else if (error == HDC_CTRL_D)
		ft_putstr_fd("msh: warning: here-document delimited by end-of-file \
		(wanted `eof')\n", STDERR_FILENO);
}
