/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/22 16:49:43 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//exec
int		ms_env(t_msh *msh, t_cmd *cmd);
int		ms_exec_builtin(t_msh *msh, t_cmd *cmd);
int		ms_pwd(void);
int		ms_echo(t_cmd *cmd);
int		ms_exit(t_msh *msh, t_cmd *cmd);
int		ms_unset(t_msh *msh, t_cmd *cmd);
int		ms_export(t_msh *msh, t_cmd *cmd);

//utils
int		cmd_is_builtin(t_cmd *cmd);
int		cmd_is_echo(t_cmd *cmd);
int		ms_atoi(char *nptr);
t_env	*unset(char *name, t_env **env);
t_env	*export(char *arg, t_env **env, int *status);

#endif
