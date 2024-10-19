/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:16:12 by saandria          #+#    #+#             */
/*   Updated: 2024/10/19 15:09:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib.h"
# include "struct.h"
# include "enum.h"

//token_utils functions
int			ms_istoken(char c);
void		handle_quotes(char *s, int *i);
void		print_token(t_token *token);
int			ms_isspace(char c);
int			is_in_simple_quotes(char *s, int *i);
int			is_in_double_quotes(char *s, int *i);
void		free_tokens(t_token **t);
void		check_inquotes(char *s, int *i);
t_token		*check_token(char *s, int *i, t_token *new_token);
t_token		*get_wordtok(char *s, int *i, t_token *new_token);
t_token		*check_if(t_token *token, char *s, int *i);
t_token		*create_token(t_tokentype type, char *value, int *i);
void		add_token(t_token **token, t_token *new);

//sig_handler
void		handle_sigint(int sig);
void		handle_sigquit(int sig);
void		ms_signal(void);

//tokenizer
t_token		*ms_tokenizer(char *s);

//re_tokenizer
t_token		*re_create(t_tokentype type, char *value);
t_token		*join_token(t_token **token);
t_token		*final_token(t_token **token);

//environment
char		**env_copy(t_env **env);
void		add_env(t_env **env, t_env *new_env);
t_env		*new_env_list(char *value);
void		print_env_list(t_env *env);
t_env		*get_env(char **env);
void		free_env(t_env **env);

//execution
char		*check_path(char *cmd, char **env);
void		exec(char **cmd, t_msh *msh);
void		free_spl(char **env);
void		exec_pipe(t_node *node, t_msh *msh);
void		ms_exec(t_node *node, t_msh *msh);
void		exec_dir(t_node *node, t_msh *msh);
void		exec_main(t_msh *msh);
int			cmd_is_builtin(char **cmd);
void		exec_built(char **cmd, char **env);
void		free_if_fd_invalid(t_msh *msh, char *file);
int			is_rout_or_append(int type);
void		exec_redirin(t_node *node, t_msh *msh);

//error handling
void		error(void);

//msh_utils
void		free_minishell(t_msh *msh);
void		free_node(t_node **node);
void		ms_init(t_msh **msh);
void		check_exit(t_msh *msh);
void		free_all(t_msh *msh);
t_bool		init_msh(t_msh **msh, int argc, char **argv, char **env);
void		exit_msh_exit(t_msh *msh, char *input);

//parsing
t_node		*parse(t_token *token);
void		print_ast(t_node **node);
int			count_token_word(t_token *token);
t_node		*init_node(t_nodetype type);

//input parse
t_env		*get_env_name(char *name, t_env *list);

//heredoc_errors
void		error_heredoc(t_msh *msh, char *input);
t_bool		set_heredoc_error(t_error *error, t_error type);
void		error_fork_heredoc(t_msh *msh, char *input);

//quote parsing
void		init_quote(t_quote *quote);
void		update_quote(char c, t_quote *quote);
t_bool		quote_closed(t_quote quote);
t_bool		is_quote(char c);
t_bool		quote_opened(t_quote quote);

//syntax_error
t_bool		set_syntax_error(t_error *error, t_error type);
void		error_fork_syntax(t_msh *msh, char *input);

// init_input
char		*get_input(t_msh *msh);
void		set_exit_status_syntax(t_msh *msh, int status, t_bool *has_error);
int			launch_syntax_validation_proc(t_msh *msh, char *input);
t_bool		has_syntax_error(t_msh *msh, char *input);

// free_msh
void		free_msh(t_msh *msh);
void		free_msh_keep_file(t_msh *msh);
void		free_msh_reset(t_msh *msh);
void		free_msh_syntax(t_msh *msh, char *input);
void		free_msh_heredoc(t_msh *msh, char *input);

// free_heredoc
void		free_heredoc(t_heredoc *heredoc);
void		free_heredoc_list(t_heredoc **list);
void		free_heredoc_keep_file(t_heredoc *heredoc);
void		free_heredoc_list_keep_file(t_heredoc **list);

// input_utils
t_bool		is_empty_line(char *line);
t_bool		is_redir(char c);
t_bool		is_redir_valid(char **input);

// input_trim
t_bool		is_trimmed(char *line);
char		*trim_sp_out(char *line);
int			trim_in_len(char *line);
char		*trim_sp_in(char *line);
char		*trim_sp_all(char *line);

// launch_syntax_validation
t_bool		has_pipe_start_end(char *input);
t_bool		has_quote_opened(char *input);
t_bool		has_pipe_succ(char *input);
t_bool		has_redir_invalid(char *input);
int			launch_syntax_validation(char *input);

// heredoc_utils
char		*set_filename(int i);
int			get_eof_len(char *input);

// heredoc_initialize
t_heredoc	*new_heredoc(void);
void		add_heredoc_list(t_heredoc **list, t_heredoc *heredoc);
t_heredoc	*create_heredoc(char **input, int i);
t_heredoc	*get_heredoc(char *input);

// init_heredoc
void		set_exit_status_heredoc(t_msh *msh, int status, t_bool *has_stop);
int			launch_heredoc_proc(t_msh *msh, char *input);
t_bool		has_heredoc_parse_input_error(t_msh *msh, char *input);

// heredoc_eof
char		*msh_strjoin(char *s1, char *s2);
char		*un_quote(char *str, t_bool do_free);
t_bool		has_to_expand_heredoc(char *eof_input);

// launch_heredoc
void		handle_heredoc_sigint(int sig);
void		set_signal_handler_heredoc(void);
void		write_file_heredoc(int fd, char *line, t_bool exp_var, t_msh *msh);
t_error		create_file_heredoc(int fd, t_msh *msh, t_heredoc *heredoc);
int			launch_heredoc(t_msh *msh);

// heredoc_parser_expander
char		*expand_var_heredoc(char *line, t_msh *msh);
char		*re_new_input_heredoc(char *old_input, char *input,
				t_heredoc **list);
char		*parse_input_heredoc(t_heredoc *list, char *input, t_bool do_free);
char		*re_new_input_var(char *old_input, char *input, int *i, t_msh *msh);
char		*expand_input_var(t_msh *msh, char *input, t_bool do_free);

//builtin
void		ms_pwd(void);
void		ms_cd(char **cmd, char **env);
void		ms_env(char **env);

#endif