/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:35:14 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:20:44 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "./enum.h"
# include "./struct.h"
# include "builtins.h"
# include "env.h"
# include "execution.h"
# include "heredoc.h"
# include "input.h"
# include "msh.h"
# include "prompt.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

t_bool	is_quote(char c);
void	init_quote(t_quote *quote);
t_bool	quote_opened(t_quote quote);
t_bool	quote_closed(t_quote quote);
void	update_quote(char c, t_quote *quote);

void	handle_sigint(int sig);
void	set_signal_handler(void);

#endif
