/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:11:17 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 11:02:28 by arakotom         ###   ########.fr       */
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

t_env	*envp_dup(char **envp);
void	*env_free(t_env *env);
void	*env_free_list(t_env *list_env);
t_env	*env_create(char *str, char sep);
t_env	*env_get(t_env *list_env, char *name);
void	env_add(t_env *list_env, t_env *new_env);
void	env_del(t_env *list_env, char *name);
#endif
