/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:11:17 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 23:23:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include "types.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	data_init(t_data *data, int argc, char **argv);
t_env	*env_new(void);
t_bool	envp_dup(t_data *data, char **envp);

t_env	*env_create(char *str);
void	env_add(t_env **list, t_env *env);

void	free_data(t_data *data);
void	free_env(t_env *env);
void	free_list_env(t_env **list);

t_bool	ms_is_quote(char c);
t_bool	ms_is_var_char(char c);

void	quote_init_state(t_quote_state *d_q, t_quote_state *s_q);
void	quote_update_state(char c, t_quote_state *d_q, t_quote_state *s_q);
t_bool	quote_opened(char *prompt);

int		ms_count_prompt(char *str);

char	*ms_trim_free(char *prompt);
void	format_data_prompt(char **str, char *prompt);

#endif
