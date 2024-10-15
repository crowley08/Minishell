/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:24:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:48:31 by arakotom         ###   ########.fr       */
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
t_bool	free_msh_reset(t_msh *msh);
void	free_msh_syntax(t_msh *msh, char *input);
void	free_msh_heredoc(t_msh *msh, char *input);

// free_heredoc
void	free_heredoc(t_heredoc *heredoc);
void	free_heredoc_list(t_heredoc **list);
void	free_heredoc_keep_file(t_heredoc *heredoc);
void	free_heredoc_list_keep_file(t_heredoc **list);

// free_prompt
void	free_arg(t_arg *arg);
void	free_arg_list(t_arg **list);
void	free_redir_in(t_redir_in *redir_in);
void	free_redir_out(t_redir_out *redir_out);
void	free_prompt(t_prompt *prompt);

// free_prompt_struct
void	free_cmd(t_cmd *cmd);
void	free_redir_in_list(t_redir_in **list);
void	free_redir_out_list(t_redir_out **list);
void	free_prompt_list(t_prompt **list);

#endif
