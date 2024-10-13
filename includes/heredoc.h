/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:16:18 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 12:47:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

// heredoc_utils
char		*set_filename(int i);
int			get_eof_len(char *input);

// heredoc_initialize
t_heredoc	*new_heredoc(void);
void		add_heredoc_list(t_heredoc **list, t_heredoc *heredoc);
t_heredoc	*create_heredoc(char **input, int i);
t_heredoc	*get_heredoc(char *input);

// init_heredoc
t_bool		has_heredoc_error(t_msh *msh, char *input);

// heredoc_eof
char		*msh_strjoin(char *s1, char *s2);
char		*un_quote(char *str, t_bool do_free);
t_bool		has_to_expand_heredoc(char *eof_input);

// launch_heredoc
void		handle_heredoc_sigint(int sig);
void		set_signal_handler_heredoc(void);
t_bool		set_heredoc_error(t_error_stt *error, t_error_stt type);
char		*expand_var_heredoc(char *line, t_msh *msh);
void		write_file_heredoc(int fd, char *line, t_bool exp_var, t_msh *msh);
t_error_stt	create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc);
int			launch_heredoc(t_msh *msh);
#endif
