/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:17:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/09 11:19:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

// init_exec
char *get_path(char *cmd, t_env *envp);
void exec_one_prompt(t_prompt *prompt, t_env *env);
void exec_prompt(t_prompt *prompt, t_env *envp);
void exec_list_prompt(t_prompt *prompt, t_env *envp);

// exec_utils
int get_len_arg(t_arg *list);
int get_len_envp(t_env *envp);
char **set_arg_execve(t_cmd *cmd);
char **set_env_execve(t_env *envp);

// redir
t_bool check_error_redir_in(t_redir_in *arg_rdr);
t_bool check_error_redir_out(t_redir_out *arg_rdr);
t_bool check_redir_error(t_redir_in *arg_rdr_in, t_redir_out *arg_rdr_out);

#endif
