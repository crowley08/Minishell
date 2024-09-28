/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:56 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 13:01:22 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

// init_input
t_bool is_input_valid(char *line);
char *get_input(void);

// input_utils
t_bool is_empty_line(char *str);
t_bool is_char_redir(char c);
t_bool set_syntax_error(t_error_stt *curr_error, t_error_stt error);

// input_validation
t_bool has_pipe_start_end_redir(char *str);
t_bool has_quote_opened(char *str);
t_bool has_dbl_pipe_succ(char *str);
t_bool has_syntax_error(char *line, t_error_stt *error);

// input_trim
char *trim_space_out(char *input);
int str_trim_in_len(char *str);
char *trim_space_in(char *input);
char *trim_space_all(char *input);

// redir_validation
t_bool is_redir_valid(char **str);
t_bool has_some_redir_invalid(char *str);

#endif
