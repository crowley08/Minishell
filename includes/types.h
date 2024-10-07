/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:00:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:00 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

typedef enum e_bool t_bool;
typedef enum e_quote_stt t_quote_stt;
typedef enum e_error_stt t_error_stt;
typedef enum e_rd_out_type t_rd_out_type;
typedef enum e_token_type t_token_type;
typedef struct s_env t_env;
typedef struct s_data t_data;
typedef struct s_quote_dt t_quote_dt;
typedef struct s_heredoc t_heredoc;
typedef struct s_arg t_arg;
typedef struct s_cmd t_cmd;
typedef struct s_redir_in t_redir_in;
typedef struct s_redir_out t_redir_out;
typedef struct s_prompt t_prompt;

#endif
