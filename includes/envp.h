/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:44:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/25 21:09:08 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

t_bool	dup_envp(t_data *data, char **envp);
t_env	*new_env(void);
void	free_env(t_env *env);
void	free_env_list(t_env **list);
t_env	*create_env(char *str);
void	add_env_list(t_env **list, t_env *env);

#endif
