/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:11:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 11:44:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

char **split_pipe(char *str);
void print_prompts(char **prompts);

// free_struct_utils
void free_arg(t_arg *arg);
void free_arg_list(t_arg **list);
void free_arg_rd_out(t_arg_rd_out *arg_rd_out);
void free_arg_rd_out_list(t_arg_rd_out **list);

// free_struct
void free_cmd(t_cmd *cmd);
void free_redir_in(t_redir_in *redir_in);
void free_redir_out(t_redir_out *redir_out);
void free_prompt(t_prompt *prompt);
void free_prompt_list(t_prompt **list);

// init_prompt
t_prompt *new_prompt(void);
int get_next_word_len(char *input);
t_prompt *create_prompt(char *input);
t_bool set_prompt_data(t_data *data, char **input_tab);

#endif
