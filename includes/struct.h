/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:11 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 11:01:29 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_env t_env;
typedef struct s_quote t_quote;
typedef struct s_heredoc t_heredoc;
typedef struct s_arg t_arg;
typedef struct s_cmd t_cmd;
typedef struct s_redir_in t_redir_in;
typedef struct s_redir_out t_redir_out;
typedef struct s_prompt t_prompt;
typedef struct s_msh t_msh;

struct s_env
{
	char *name;
	char *value;
	t_env *next;
};

struct s_quote
{
	t_quote_state d_q;
	t_quote_state s_q;
};

struct s_heredoc
{
	char *eof;
	char *tmp_file;
	t_bool exp_var;
	t_heredoc *next;
};

struct s_arg
{
	char *value;
	t_arg *next;
};

struct s_cmd
{
	char *value;
	t_arg *arg_list;
};

struct s_redir_in
{
	char *file;
	t_redir_in *next;
};

struct s_redir_out
{
	char *file;
	t_redir_out_type type;
	t_redir_out *next;
};

struct s_prompt
{
	t_cmd *cmd;
	t_redir_in *redir_in_list;
	t_redir_out *redir_out_list;
	t_prompt *next;
};

struct s_msh
{
	int exit_status;
	int std_in;
	int std_out;
	char *input;
	t_env *env_list;
	t_heredoc *heredoc_list;
	t_prompt *prompt_list;
};

#endif
