/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:32:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:37:55 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env		t_env;
typedef struct s_msh		t_msh;
typedef struct s_quote_dt	t_quote_dt;

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

struct						s_msh
{
	t_env					*env_list;
	int						exit_status;
};
struct						s_quote_dt
{
	t_quote_stt				d_q;
	t_quote_stt				s_q;
};

#endif
