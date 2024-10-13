/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:23:12 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:46:56 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

t_env	*new_env(void);
t_env	*create_env(char *str);
void	add_env_list(t_env **list, t_env *env);
t_bool	dup_envp(t_msh *msh, char *envp[]);
t_env	*get_env(char *name, t_env *list);

#endif
