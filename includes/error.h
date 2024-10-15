/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:32:45 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:01 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// error_parse
void	error_dup_env(t_msh *msh);
void	error_syntax_heredoc(t_msh *msh, char *input);
void	print_syntax_error(t_error_stt error);
t_bool	set_error(t_error_stt *error, t_error_stt type);
void	error_fork(t_msh *msh, char *input);

#endif
