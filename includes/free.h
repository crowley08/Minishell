/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:24:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 18:16:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

// free_env
void	free_env(t_env *env);
void	free_env_list(t_env **list);

// free_msh
void	free_msh(t_msh *msh);
void	free_msh_keep_file(t_msh *msh);

void	free_msh_reset(t_msh *msh);
void	free_msh_syntax(t_msh *msh, char *input);
void	free_msh_heredoc(t_msh *msh, char *input);

// free_heredoc
void	free_heredoc(t_heredoc *heredoc);
void	free_heredoc_list(t_heredoc **list);
void	free_heredoc_keep_file(t_heredoc *heredoc);
void	free_heredoc_list_keep_file(t_heredoc **list);

#endif
