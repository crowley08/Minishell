/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:16:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/19 11:22:28 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_env		t_env;
typedef struct s_data		t_data;
typedef enum e_bool			t_bool;
typedef enum e_quote_state	t_quote_state;

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

struct						s_data
{
	t_env					*envp;
	char					*prompt;
};

enum						e_quote_state
{
	OPENED,
	CLOSED
};

enum						e_bool
{
	FALSE,
	TRUE
};

#endif
