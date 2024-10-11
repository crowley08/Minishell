/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:06:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/11 23:36:41 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_bool			t_bool;
typedef enum e_quote_stt	t_quote_stt;

enum						e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum e_quote_stt
{
	CLOSED = 0,
	OPENED = 1
};

#endif
