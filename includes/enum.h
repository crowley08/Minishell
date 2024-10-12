/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:06:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 13:34:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
#define ENUM_H

typedef enum e_bool t_bool;
typedef enum e_quote_stt t_quote_stt;
typedef enum e_error_stt t_error_stt;

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum e_quote_stt
{
	CLOSED = 0,
	OPENED = 1
};

enum e_error_stt
{
	NOTHING = 0,
	STX_QUOTE = 1,
	STX_PIPE_START_END = 2,
	STX_PIPE_SUCC = 3,
	STX_REDIR = 4,
};
#endif