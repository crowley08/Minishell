/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:16:18 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 16:59:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
#define HEREDOC_H

// heredoc_utils
char *set_filename(int i);
int get_eof_len(char *input);

// heredoc_initialize
t_heredoc *new_heredoc(void);
void add_heredoc_list(t_heredoc **list, t_heredoc *heredoc);
t_heredoc *create_heredoc(char **input, int i);
t_heredoc *get_heredoc(char *input);

// init_heredoc
t_bool has_heredoc_error(t_msh *msh, char *input);

// heredoc_eof
char *msh_strjoin(char *s1, char *s2);
char *un_quote(char *str, t_bool do_free);
t_bool has_to_expand_heredoc(char *eof_input);
#endif
