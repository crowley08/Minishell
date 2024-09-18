/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:16:00 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 16:18:33 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_env		t_env;
typedef enum e_bool			t_bool;
typedef enum e_quote_state	t_quote_state;

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

enum						e_quote_state
{
	opened,
	closed
};

enum						e_bool
{
	false,
	true
};

#endif
