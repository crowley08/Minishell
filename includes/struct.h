/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 06:57:06 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 07:44:34 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

struct s_env
{
	char *name;
	char *value;
	t_env *next;
};

struct s_data
{
	t_env *envp;
	char *input;
	t_error_stt curr_error;
	t_prompt *prompt;
};

struct s_quote_dt
{
	t_quote_stt d_q;
	t_quote_stt s_q;
};
struct s_heredoc
{
	char *eof;
	char *filename;
	t_bool expend_var;
	t_heredoc *next;
};

// at school
struct s_arg
{
	char *value;
	t_arg *next;
};

struct s_cmd
{
	char *cmd;
	t_arg *args;
};

struct s_redir_in
{
	char *value;
	t_arg *files;
};

struct s_arg_rd_out
{
	char *file;
	t_rd_out_type type;
	t_arg_rd_out *next;
};

struct s_redir_out
{
	char *value;
	t_arg_rd_out *files;
};

struct s_prompt
{
	t_cmd *cmd;
	t_redir_in *redir_in;
	t_redir_out *redir_out;
	t_prompt *next;
};

#endif
