/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:46:49 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 10:33:16 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_bool				t_bool;
typedef enum e_quote_stt		t_quote_stt;
typedef enum e_error_stt		t_error_stt;
typedef enum e_redir_out_type	t_redir_out_type;
typedef enum e_token_type		t_token_type;

enum							e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum							e_quote_stt
{
	CLOSED = 0,
	OPENED = 1
};

enum							e_error_stt
{
	NOTHING = 0,
	STX_QUOTE = 1,
	STX_PIPE_START_END = 2,
	STX_PIPE_SUCC = 3,
	STX_REDIR = 4,
	HEREDOC_EOF = 5,
	HEREDOC_SIGINT = 6,
	HEREDOC_FD = 7
};

enum							e_redir_out_type
{
	RO_TRUNC = 1,
	RO_APPEND = 2
};

enum							e_token_type
{
	WORD = 0,
	REDIR_IN = 1,
	REDIR_OUT = 2
};

#endif
