/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:55 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 10:18:15 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

//* free_prompt_struct
t_bool free_arg(t_arg *arg, t_bool val);
t_bool free_arg_list(t_arg **list, t_bool val);
t_bool free_redir_in(t_redir_in *redir_in, t_bool val);
t_bool free_redir_out(t_redir_out *redir_out, t_bool val);
t_bool free_prompt(t_prompt *prompt, t_bool val);
//* free_prompt
t_bool free_cmd(t_cmd *cmd, t_bool val);
t_bool free_redir_in_list(t_redir_in **list, t_bool val);
t_bool free_redir_out_list(t_redir_out **list, t_bool val);
t_bool free_prompt_list(t_prompt **list, t_bool val);
//* prompt_split_pipe
int count_pipe(char *input);
int set_next_pipe(char **tab, char *input, int tab_index);
t_bool pipe_splitted(char **tab, char *input);
char **split_pipe(char *input);
//* prompt_cmd_token
t_bool prompt_create_cmd(t_prompt *prompt, char *value);
t_bool prompt_add_cmd_arg(t_prompt *prompt, char *arg);
//* prompt_redir_in_token
t_redir_in *prompt_create_redir_in(char *file);
t_bool prompt_add_redir_in(t_prompt *prompt, char *file);
//* prompt_redir_out_token
t_redir_out *prompt_create_redir_out(char *file, t_redir_out_type type);
t_bool prompt_add_redir_out(t_prompt *prompt, char *file,
							t_redir_out_type type);
//* prompt_utils
int next_value_len(char *input);
t_token_type get_token_type(char *value);
int set_token_redir(t_prompt **prompt, char *value, char *input);
int set_prompt_token(t_prompt **prompt, char *value, char *input);
//* init_prompt
t_prompt *new_prompt(void);
t_prompt *create_prompt(char *input);
void add_prompt_list(t_prompt **list, t_prompt *prompt);
t_prompt *parse_input_prompt(char **tab);
t_bool parse_token_prompt_ok(t_msh *msh);
//* print_prompt
void print_prompts(t_prompt *prompt);
void print_arg(t_arg *arg);
void print_prompt_cmd(t_cmd *cmd);
void print_prompt_redir_in(t_redir_in *redir_in);
void print_prompt_redir_out(t_redir_out *redir_out);
#endif
