/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:16:12 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:37:37 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h" 
# include <term.h>
# include <fcntl.h>

typedef enum e_bool			t_bool;
typedef struct s_token		t_token;
typedef enum e_tokentype	t_tokentype;
typedef enum e_nodetype		t_nodetype;
typedef struct s_env		t_env;
typedef struct s_msh		t_msh;
typedef struct s_node		t_node;
typedef enum e_error_stat	t_error_stat;
typedef struct s_quote_type	t_quote_type;
typedef enum e_quote_status	t_quote_status;
typedef struct s_heredoc	t_heredoc;

enum	e_bool
{
	F = 0,
	T = 1,
};

enum	e_quote_status
{
	CLOSED = 0,
	OPENED = 1,
};

struct				s_quote_type
{
	t_quote_status		d_q;
	t_quote_status		s_q;
};

enum	e_error_stat
{
	INIT = -1,
	NOTHING = 0,
	QUOTE = 1,
	PIPE_START_END = 2,
	PIPE_DBL_SUCC = 3,
	REDIR = 4,
};

struct				s_heredoc
{
	char			*eof;
	char			*filename;
	t_bool			expend_var;
	t_heredoc		*next;
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
};

struct	s_token
{
	t_tokentype		type;
	char			*value;
	t_token			*next;
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
	char	*input;
	t_node	*node;
	t_token	*token;
	t_token	*expand;
	t_env	*envp;
	char	**envc;
};

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

//error handling
void		error(void);

//msh_utils
void		free_minishell(t_msh *msh);
int			count_pipe(t_msh *msh);
void		free_node(t_node **node);
void		init_msh(t_msh **msh);
void		check_exit(t_msh *msh);
void		free_all(t_msh *msh);

//parsing
t_node		*parse(t_token *token);
void		print_ast(t_node **node);

//builtin
void		ms_pwd(void);
void		ms_cd(char **cmd, char **env);
void		ms_env(char **env);

//input handling
char		*trim_space_out(char *input);
int			str_trim_in_len(char *str);
char		*trim_space_in(char *input);
char		*trim_space_all(char *input);
t_bool		line_is_empty(char *str);
t_bool		is_quote(char c);
void		init_quote_dt(t_quote_type *quote);
t_bool		has_quote_opened(char *str);
t_bool		set_syntax_error(t_error_stat *curr_error, t_error_stat error);
t_bool		is_char_redir(char c);
t_bool		has_pipe_start_end_redir(char *str);
t_bool		has_dbl_pipe_succ(char *str);
t_bool		is_redir_valid(char **str);
t_bool		has_some_redir_invalid(char *str);
t_bool		has_syntax_error(char *line, t_error_stat *error);
t_bool		is_input_valid(char *line);
char		*get_input(void);
void		update_quote_dt(char c, t_quote_type *quote);

//input parsing
t_heredoc	*new_heredoc(void);
char		*set_filename_heredoc(int i);
int			get_len_eof_line(char *input);
char		*heredoc_strjoin(char *s1, char *s2);
void		complete_eof_name(char *eof_line, int *start, int *end, char **eof);
char		*set_eof_heredoc(char *eof_line, t_bool *expander_var);
t_heredoc	*create_heredoc(char **input, int i);
void		add_heredoc_list(t_heredoc **list, t_heredoc *heredoc);
t_heredoc	*get_all_heredoc(char *input);
t_bool		is_empty_line(char *str);
char		*expander_var(char *str, t_env *envp);
void		write_heredoc_input(int fd, char *input,
				t_bool exp_var, t_env *envp);
t_bool		fill_file_input(int fd, t_heredoc heredoc, t_env *envp);
t_bool		create_file_heredoc(t_heredoc *list, t_env *envp);
char		*re_new_input_heredoc(char *old_input, char *input,
				t_heredoc **list);
char		*get_new_input_heredoc(char *input, t_heredoc *list,
				t_bool do_free);
void		free_heredoc_list(t_heredoc **list);
char		*re_new_input_expander(char *old_input, char *input,
				int *i, t_env **list);
char		*get_new_input_expander(char *input, t_env *envp, t_bool do_free);
char		*parse_input_var(char *input, t_env *envp);
void		free_heredoc(t_heredoc *heredoc);
t_env		*get_env_name(char *name, t_env *list);

/*
//expanding
t_token	*expand_token(t_token *token);
t_token	*ms_expand(t_token **token);
*/

#endif