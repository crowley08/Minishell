/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:56 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/27 15:31:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

char *get_input(void);
t_bool is_char_redir(char c);
t_bool is_empty(char *str);
t_bool is_pipe_start_end_redir(char *str);
t_bool is_quote_opened(char *str);
t_bool is_have_dbl_pipe_succ(char *str);
t_bool set_input_error(t_error_stt *curr_error, t_error_stt error);
t_bool is_some_redir_invalid(char *str);
t_bool is_redir_wrong(char **str);
t_bool input_valid(t_data *data);

#endif
