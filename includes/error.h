/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:32:45 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:49:55 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// error_env
void	error_dup_env(t_msh *msh);

// error_input
void	error_syntax(t_msh *msh, char *input);
void	print_syntax_error(t_error_stt error);
t_bool	set_syntax_error(t_error_stt *error, t_error_stt type);

// error_fork
void	error_fork_syntax(t_msh *msh, char *input);
void	error_fork_heredoc(t_msh *msh, char *input);
t_bool	error_fork_execute(void);

// error_heredoc
void	error_heredoc(t_msh *msh, char *input);
t_bool	set_heredoc_error(t_error_stt *error, t_error_stt type);

// error_prompt
void	error_prompt_split(t_msh *msh);
void	error_prompt_token(t_msh *msh);
#endif
