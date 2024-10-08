/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:11:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 10:58:00 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

// init_prompt
t_prompt		*new_prompt(void);
int				get_next_word_len(char *input);
int				fill_prompt_token(t_prompt **prompt, char *value, char *input);
t_prompt		*create_prompt(char *input);
t_bool			set_prompt_data(t_data *data, char **input_tab);
void			add_prompt_list(t_prompt **list, t_prompt *prompt);

// prompt_split
char			**split_pipe(char *str);

// prompt_utils
void			print_prompts(t_prompt *prompt);
t_token_type	get_token_type(char *value);
void			print_arg(t_arg *arg);
void			print_prompt_cmd(t_cmd *cmd);
void			print_prompt_redir_in(t_redir_in *redir_in);
void			print_prompt_redir_out(t_redir_out *redir_out);

// free_struct_utils
void			free_arg(t_arg *arg);
void			free_arg_list(t_arg **list);
void			free_redir_in_list(t_redir_in **list);
void			free_redir_out_list(t_redir_out **list);

// free_struct
void			free_cmd(t_cmd *cmd);
void			free_redir_in(t_redir_in *redir_in);
void			free_redir_out(t_redir_out *redir_out);
void			free_prompt(t_prompt *prompt);
void			free_prompt_list(t_prompt **list);

// init_prompt
t_prompt		*new_prompt(void);
t_prompt		*create_prompt(char *input);
void			add_prompt_list(t_prompt **list, t_prompt *prompt);
t_bool			set_prompt_data(t_data *data, char **input_tab);

// init_token_prompt
int				get_next_word_len(char *input);
int				fill_token_redir_out(t_prompt **prompt, char *value,
					char *input);
int				fill_prompt_token(t_prompt **prompt, char *value, char *input);

// prompt_cmd
t_bool			prompt_create_cmd(t_prompt *prompt, char *value);
t_bool			prompt_add_cmd_arg(t_prompt *prompt, char *arg);

// prompt_redir_in
t_redir_in		*prompt_create_redir_in(char *file);
t_bool			prompt_add_file_redir_in(t_prompt *prompt, char *file);

// prompt_redir_out
t_redir_out		*prompt_create_redir_out(char *file, t_rd_out_type type);
t_bool			prompt_add_file_redir_out(t_prompt *prompt, char *file,
					t_rd_out_type type);

#endif
