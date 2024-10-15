/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:55:33 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:20:00 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

// exec_redir_validation
t_bool	set_error_redir(t_error_stt type);
t_bool	has_error_redir_in(t_redir_in *redir);
t_bool	has_error_redir_out(t_redir_out *redir);
t_bool	has_error_redir_exec(t_prompt *prompt);

// exec_set_redir
t_bool	set_redir_stdout_error(t_redir_out *redir);
t_bool	set_redir_stdin_error(t_redir_in *redir);
t_bool	set_redir_std_in_out_error(t_prompt *prompt);
t_bool	set_redir_std_in_out_error(t_prompt *prompt);

// init_execute
t_bool	execute_prompt_child_pipe(t_msh *msh, t_prompt *prompt);
t_bool	execute_prompt_last(t_msh *msh, t_prompt *prompt, int stn_out);
void	set_exit_status_exec(t_msh *msh, int status, t_bool *has_error);
int		launch_exec_prompt_child_pipe(t_msh *msh, t_prompt *prompt);
t_bool	execute_prompts_list_error(t_msh *msh);

// exec_execve_utils
int		arg_list_len(t_arg *list);
int		env_list_len(t_env *list);
void	reset_std_in_out(int *std_in, int *std_out);

// exec_execve
char	*search_path(char *cmd_value, t_env *env_list);
char	**set_argv_execve(t_cmd *cmd);
char	**set_envp_execve(t_env *env_list);
int		exec_execve(t_msh *msh, t_cmd *cmd);

#endif
