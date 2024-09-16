/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:45:17 by saandria          #+#    #+#             */
/*   Updated: 2024/09/09 09:43:03 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	printf("\n\033[1;91m$>\033[0m ");
}

void	handle_sigquit(int sig)
{
	(void)sig;
}

void	ms_signal(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	signal(SIGINT, handle_sigint);
	sigaction(SIGQUIT, &sa, NULL);
}
