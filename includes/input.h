/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:29:37 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

//* input_utils
t_bool			is_empty_str(char *str);
t_bool			is_redir(char c);
t_bool			is_redir_valid(char **input);
//* input_trim
t_bool			is_trimmed(char *line);
char			*trim_space_out(char *line);
int				trim_in_len(char *line);
char			*trim_space_in(char *line);
char			*trim_space_all(char *line);
//*init_input
t_bool			get_input_line_ok(t_msh *msh);
void			set_exit_status_msh_stx(t_msh *msh, t_error_state exit_status,
					t_bool *has_err);
void			run_syntax_validation(t_msh *msh);
t_bool			syntax_input_ok(t_msh *msh);
//*err_input
void			print_err_stx(t_error_state error);
//*syntax_validation
t_bool			has_pipe_start_end(char *input);
t_bool			has_quote_opened(char *input);
t_bool			has_pipe_succ(char *input);
t_bool			has_redir_invalid(char *input);
t_error_state	check_syntax_validation(char *input);
#endif
