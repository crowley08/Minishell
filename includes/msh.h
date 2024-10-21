/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:08 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/20 21:28:51 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
//*init_msh
void	init_msh_ok(int argc, char *argv[], t_msh *msh);
void	exit_msh_eof(t_msh *msh);
void	run_msh(t_msh *msh);
//*free_msh
t_bool	free_msh(t_msh *msh, t_bool val);
t_bool	free_msh_keep_file(t_msh *msh, t_bool val);
t_bool	free_msh_reset(t_msh *msh, t_bool val);
//*err_msh
t_bool	reset_msh_err_get_input_line(t_msh *msh, t_bool val);
void	exit_err_fork(t_msh *msh);

#endif
