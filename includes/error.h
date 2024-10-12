/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:32:45 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 12:20:41 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// error_env
void	error_dup_env(t_msh *msh);

// error_input
void error_syntax(t_msh *msh, char *input);

#endif
