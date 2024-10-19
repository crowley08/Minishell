/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:06:13 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 13:11:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enum.h"

typedef struct s_token		t_token;
typedef struct s_env		t_env;
typedef struct s_msh		t_msh;
typedef struct s_node		t_node;
typedef struct s_heredoc	t_heredoc;
typedef struct s_quote		t_quote;

struct	s_heredoc
{
	char		*eof;
	char		*tmp_file;
	t_bool		exp_var;
	t_heredoc	*next;
};

struct	s_quote
{
	t_quote_stat	d_q;
	t_quote_stat	s_q;
};

struct	s_token
{
	t_tokentype		type;
	char			*value;
	t_token			*next;
	t_token			*prev;
};

struct	s_env
{
	char	*name;
	char	*value;
	t_env	*next;
};

struct	s_node
{
	char		**cmd;
	t_nodetype	type;
	t_node		*left;
	t_node		*right;
};
/*
*/

struct	s_msh
{
	char		*input;
	t_node		*node;
	int			exit_status;
	t_token		*token;
	t_heredoc	*heredoc;
	t_env		*envp;
	char		**envc;
};

#endif