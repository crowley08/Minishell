/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:17:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 15:19:34 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

// init_exec
char *get_path(char *cmd, t_env *envp);
void exec_one_prompt(t_prompt *prompt, t_env *env);
void exec_list_prompt(t_prompt *list, t_env *envp);

// exec_utils
int get_len_arg(t_arg *list);
int get_len_envp(t_env *envp);
char **set_arg_execve(t_prompt *prompt);
char **set_env_execve(t_env *envp);

// free
int get_len_tab_str(char **list);
void free_arg_env_exec(char **list);

#endif
