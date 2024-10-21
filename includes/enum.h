/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 09:28:15 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_bool				t_bool;
typedef enum e_quote_state		t_quote_state;
typedef enum e_error_state		t_error_state;
typedef enum e_token_type		t_token_type;
typedef enum e_redir_out_type	t_redir_out_type;

enum							e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum							e_quote_state
{
	CLOSE = 0,
	OPEN = 1
};

enum							e_error_state
{
	NOTHING = EXIT_SUCCESS,
	ERROR = EXIT_FAILURE,
	STX_QUOTE = 2,
	STX_PIPE = 3,
	STX_REDIR = 4,
	HDC_FD = 5,
	HDC_CTRL_C = 6,
	HDC_CTRL_D = 7
};

enum							e_token_type
{
	WORD = 0,
	REDIR_IN = 1,
	REDIR_OUT = 2
};

enum							e_redir_out_type
{
	RO_TRUNC = 0,
	RO_APPEND = 1
};

#endif
