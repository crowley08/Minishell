/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:32:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 22:03:14 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env	t_env;
typedef struct s_msh	t_msh;

struct					s_env
{
	char				*name;
	char				*value;
	t_env				*next;
};

struct					s_msh
{
	t_env				*env_list;
	int					exit_status;
};

#endif
