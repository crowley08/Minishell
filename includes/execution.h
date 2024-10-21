/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:01 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 15:28:51 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

//* init_execute
void exit_err_pipe(t_msh *msh);
t_bool print_err_redir(t_bool val);
void execute_msh(t_msh *msh);
//* execute_utils
int arg_list_len(t_arg *list);
int env_list_len(t_env *list);
//*execute_cmd
char *search_path(char *cmd_value, t_env *env_list);
char **set_argv_execve(t_cmd *cmd);
char **set_envp_execve(t_env *env_list);
int exec_execve(t_msh *msh, t_cmd *cmd);
int execute_cmd_in_list(t_msh *msh, t_prompt *prompt);
//* execute_set_redir
t_bool check_redir_in_ok(t_redir_in *redir);
t_bool check_redir_out_ok(t_redir_out *redir);
t_bool set_redir_in_ok(t_redir_in *redir);
t_bool set_redir_out_ok(t_redir_out *redir);
t_bool set_all_redir_ok(t_prompt *prompt);
//* execute_list_prompt
void set_exit_status_msh_exec_one_last_cmd(t_msh *msh, int exit_status);
void execute_last_cmd_in_list(t_msh *msh, t_prompt *prompt);
void execute_list_prompt(t_msh *msh, t_prompt *list);
//*execute_one_prompt
void execute_one_prompt(t_msh *msh, t_prompt *prompt);

#endif
