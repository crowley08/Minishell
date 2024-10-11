/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:24:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:44:34 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

// free_env
void	free_env(t_env *env);
void	free_env_list(t_env **list);

// free_msh
void	free_msh(t_msh *msh);

#endif
