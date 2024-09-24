/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:00:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/25 00:13:41 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_bool			t_bool;
typedef enum e_quote_stt	t_quote_stt;
typedef struct s_env		t_env;
typedef struct s_quote_dt	t_quote_dt;

enum						e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum						e_quote_stt
{
	OPENED = 200,
	CLOSED = 400
};

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

struct						s_quote_dt
{
	t_quote_stt				d_quote;
	t_quote_stt				s_quote;
};

#endif
