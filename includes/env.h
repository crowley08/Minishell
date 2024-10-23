/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/23 16:08:42 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

//* init_env
t_env	*new_env(void);
t_env	*create_env(char *str);
void	add_env_list(t_env **list, t_env *env);
t_bool	dup_envp_ok(t_msh *msh, char *envp[]);
t_env	*get_env(char *name, t_env *list);
//* free_env
t_bool	free_env(t_env *env, t_bool val);
t_bool	free_env_list(t_env **list, t_bool val);
void	exit_err_dup_env(t_msh *msh);
#endif
