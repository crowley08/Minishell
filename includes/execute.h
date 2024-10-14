/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:55:33 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 17:25:31 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

// exec_redir_validation
t_bool set_error_redir(t_error_stt type);
t_bool has_error_redir_in(t_redir_in *redir);
t_bool has_error_redir_out(t_redir_out *redir);
t_bool has_error_redir_exec(t_prompt *prompt);

// exec_set_redir
t_bool set_redir_stdout_error(t_redir_out *redir);
t_bool set_redir_stdin_error(t_redir_in *redir);
t_bool set_redir_std_in_out_error(t_prompt *prompt);
t_bool set_redir_std_in_out_error(t_prompt *prompt);

// init_execute
void execute_prompt_child(t_prompt *prompt);
t_bool execute_prompts_list(t_msh *msh);
#endif
