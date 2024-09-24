/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:16:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/22 22:43:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_quote_state	t_quote_state;
typedef enum e_bool			t_bool;
typedef struct s_env		t_env;
typedef struct s_data		t_data;
typedef struct s_quote_data	t_quote_data;

enum						e_quote_state
{
	OPENED = 200,
	CLOSED = 500
};

enum						e_bool
{
	FALSE = 0,
	TRUE = 1,
	ERROR = -400
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
	char					**prompts;
};

struct						s_quote_data
{
	t_quote_state			d_q;
	t_quote_state			s_q;
};

#endif
