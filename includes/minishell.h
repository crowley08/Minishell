/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:38:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include "./enum.h"
# include "./struct.h"
# include "env.h"
# include "error.h"
# include "free.h"
# include <stdio.h>

// init_msh
t_bool	init_msh(t_msh *msh, int argc, char *argv[], char *envp[]);

#endif
