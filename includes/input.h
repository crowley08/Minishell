/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:05:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 12:23:08 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

// init_input
char *get_input(t_msh *msh);

// input_utils
t_bool is_empty_line(char *line);

// input_trim
t_bool is_trimmed(char *line);
char *trim_sp_out(char *line);
int trim_in_len(char *line);
char *trim_sp_in(char *line);
char *trim_sp_all(char *line);

// input_syntax
void set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error);
t_bool has_syntax_error(t_msh *msh, char *input);
#endif
