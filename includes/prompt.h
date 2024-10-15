/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:01:01 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:43 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

// prompt_split_pipe
int				count_pipe(char *input);
int				set_next_pipe(char **tab, char *input, int tab_index);
t_bool			pipe_splitted(char **tab, char *input);
char			**split_pipe(char *input);
void			print_prompt_splitted(char **tab);

// init_prompt
void			test_split_pipe(char *input);
t_bool			set_exit_status_split(t_msh *msh);
t_bool			set_exit_status_token(t_msh *msh);
t_bool			has_parse_token_prompt_error(t_msh *msh);

// prompt_cmd_token
t_bool			prompt_create_cmd(t_prompt *prompt, char *value);
t_bool			prompt_add_cmd_arg(t_prompt *prompt, char *arg);

// prompt_redir_in_token
t_redir_in		*prompt_create_redir_in(char *file);
t_bool			prompt_add_redir_in(t_prompt *prompt, char *file);

// prompt_redir_out_token
t_redir_out		*prompt_create_redir_out(char *file, t_redir_out_type type);
t_bool			prompt_add_redir_out(t_prompt *prompt, char *file,
					t_redir_out_type type);

// prompt_tokenizer
t_token_type	get_token_type(char *value);
int				set_prompt_token(t_prompt **prompt, char *value, char *input);

// prompt_parser
t_prompt		*new_prompt(void);
int				next_value_len(char *input);
t_prompt		*create_prompt(char *input);
t_prompt		*parse_prompt(char **tab);

#endif
