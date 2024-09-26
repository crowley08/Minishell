/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:00:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 11:04:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_bool			t_bool;
typedef enum e_quote_stt	t_quote_stt;
typedef enum e_error_stt	t_error_stt;
typedef struct s_env		t_env;
typedef struct s_data		t_data;
typedef struct s_quote_dt	t_quote_dt;

enum						e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum						e_quote_stt
{
	CLOSED = 0,
	OPENED = 1,
};

enum						e_error_stt
{
	NOTHING = 0,
	STX_QUOTE = 1,
	STX_PIPE_START_END = 2,
	STX_PIPE_DBL_SUCC = 3,
};

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

struct						s_data
{
	t_env					*envp;
	char					*input;
	t_error_stt				curr_error;
	char					**prompt;
};

struct						s_quote_dt
{
	t_quote_stt				d_q;
	t_quote_stt				s_q;
};

#endif
