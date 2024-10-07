/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 06:56:16 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 15:23:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
#define ENUM_H

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum e_quote_stt
{
	CLOSED = 0,
	OPENED = 1,
};

enum e_error_stt
{
	INIT = -1,
	NOTHING = 0,
	STX_QUOTE = 1,
	STX_PIPE_START_END = 2,
	STX_PIPE_DBL_SUCC = 3,
	STX_REDIR = 4,
};

enum e_rd_out_type
{
	REDIR_TRUNC = 1,
	REDIR_APPEND = 2,
};

enum e_token_type
{
	WORD = 0,
	REDIR_IN = 1,
	REDIR_OUT = 2
};

#endif
