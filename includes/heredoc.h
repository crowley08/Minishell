/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:03 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 23:34:47 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

//* free_heredoc
t_bool			free_heredoc(t_heredoc *heredoc, t_bool val);
t_bool			free_heredoc_list(t_heredoc **list, t_bool val);
t_bool			free_heredoc_keep_file(t_heredoc *heredoc, t_bool val);
t_bool			free_heredoc_list_keep_file(t_heredoc **list, t_bool val);
//* heredoc_utils
char			*msh_strjoin(char *s1, char *s2);
char			*un_quote(char *str, t_bool do_free);
t_bool			has_to_expand_heredoc(char *eof_input);
char			*set_filename(int i);
int				get_eof_len(char *input);
//* heredoc_initializer
t_heredoc		*new_heredoc(void);
t_heredoc		*create_heredoc(char **input, int i);
void			add_heredoc_list(t_heredoc **list, t_heredoc *heredoc);
t_heredoc		*get_heredoc(char *input);
//* err_heredoc
void			print_err_hdc(t_error_state error);
//* init_heredoc
void			set_exit_status_msh_hdc(t_msh *msh, t_error_state exit_status,
					t_bool *has_stop);
void			run_heredoc(t_msh *msh);
t_bool			heredoc_parse_input_ok(t_msh *msh);
//* heredoc_expander
char			*expand_var(char *line, t_msh *msh);
char			*re_new_input_heredoc(char *old_input, char *input,
					t_heredoc **list);
char			*parse_input_heredoc(t_heredoc *list, char *input,
					t_bool do_free);
char			*re_new_input_var(char *old_input, char *input, int *i,
					t_msh *msh);
char			*expand_input_var(t_msh *msh, char *input, t_bool do_free);
//* parser_heredoc
void			handle_heredoc_sigint(int sig);
void			set_signal_handler_heredoc(void);
void			write_file_heredoc(int fd, char *line, t_bool exp_var,
					t_msh *msh);
t_error_state	create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc);
t_error_state	check_parser_heredoc(t_msh *msh);

#endif
