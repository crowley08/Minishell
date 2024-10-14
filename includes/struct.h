/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/11 21:32:25 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/12 16:22:18 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env		t_env;
typedef struct s_msh		t_msh;
typedef struct s_quote_dt	t_quote_dt;
typedef struct s_heredoc	t_heredoc;
typedef struct s_arg		t_arg;
typedef struct s_cmd		t_cmd;
typedef struct s_redir_in	t_redir_in;
typedef struct s_redir_out	t_redir_out;
typedef struct s_prompt		t_prompt;

struct						s_env
{
	char					*name;
	char					*value;
	t_env					*next;
};

struct						s_msh
{
	t_env					*env_list;
	int						exit_status;
	char					*input;
	t_heredoc				*heredoc;
};
struct						s_quote_dt
{
	t_quote_stt				d_q;
	t_quote_stt				s_q;
};

struct						s_heredoc
{
	char					*eof;
	char					*tmp_file;
	t_bool					exp_var;
	t_heredoc				*next;
};

struct						s_arg
{
	char					*value;
	t_arg					*next;
};

struct						s_cmd
{
	char					*value;
	t_arg					*arg_list;
};

struct						s_redir_in
{
	char					*file;
	t_redir_in				*next;
};

struct						s_redir_out
{
	char					*file;
	t_redir_out_type		*type;
	t_redir_out				*next;
};

struct						s_prompt
{
	t_cmd					*cmd;
	t_redir_in				redir_in_list;
	t_redir_out				redir_out_list;
	t_prompt				*next;
};

#endif
