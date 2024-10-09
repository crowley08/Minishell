/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:58:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/09 11:21:13 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include "./types.h"
# include "enum.h"
# include "envp.h"
# include "execution.h"
# include "input.h"
# include "prompt.h"
# include "struct.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	init_data(t_data *data, int argc, char **argv);
void	free_data(t_data *data);
void	reset_data(t_data *data);

void	init_quote_dt(t_quote_dt *quote);
void	update_quote_dt(char c, t_quote_dt *quote);
t_bool	is_quote(char c);

#endif
