/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:09:17 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 13:10:01 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_tokentype	t_tokentype;
typedef enum e_nodetype		t_nodetype;
typedef enum e_bool			t_bool;
typedef enum e_quote_stat	t_quote_stat;
typedef enum e_error		t_error;

enum	e_bool
{
	F = 0,
	T = 1,
};

enum	e_error
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

enum	e_quote_stat
{
	CLOSED = 0,
	OPENED = 1
};

enum	e_tokentype
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIRIN,
	TOK_REDIROUT,
	TOK_APPEND,
	TOK_HEREDOC,
};

enum	e_nodetype
{
	CMD_NODE,
	PIPE_NODE,
	REDIR_OUT_NODE,
	REDIR_IN_NODE,
	APPEND_NODE,
};

#endif