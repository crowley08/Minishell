/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:42:50 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include "./enum.h"
# include "./struct.h"
# include "env.h"
# include "error.h"
# include "free.h"
# include "input.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>

// init_msh
t_bool	init_msh(t_msh *msh, int argc, char *argv[], char *envp[]);
void	exit_msh_sig(t_msh *msh);

// signals
void	handle_sigint(int sig);
void	set_signal_handler(void);

// quote
t_bool	is_quote(char c);
void	init_quote(t_quote_dt *quote);
t_bool	quote_opened(t_quote_dt quote);
t_bool	quote_closed(t_quote_dt quote);
void	update_quote(char c, t_quote_dt *quote);
#endif
