/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:16:12 by saandria          #+#    #+#             */
/*   Updated: 2024/10/10 17:27:10 by saandria         ###   ########.fr       */
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

typedef struct s_token		t_token;
typedef enum e_tokentype	t_tokentype;
typedef enum e_nodetype		t_nodetype;
typedef struct s_env		t_env;
typedef struct s_msh		t_msh;
typedef struct s_node		t_node;

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
	t_env	*envp;
	char	**envc;
};

//token_utils functions
int		ms_istoken(char c);
void	handle_quotes(char *s, int *i);
void	print_token(t_token *token);
int		ms_isspace(char c);
int		is_in_simple_quotes(char *s, int *i);
int		is_in_double_quotes(char *s, int *i);
void	free_tokens(t_token **t);
void	check_inquotes(char *s, int *i);
t_token	*check_token(char *s, int *i, t_token *new_token);
t_token	*get_wordtok(char *s, int *i, t_token *new_token);
t_token	*check_if(t_token *token, char *s, int *i);
t_token	*create_token(t_tokentype type, char *value, int *i);
void	add_token(t_token **token, t_token *new);

//sig_handler
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	ms_signal(void);

//tokenizer
t_token	*ms_tokenizer(char *s);

//environment
char	**env_copy(t_env **env);
void	add_env(t_env **env, t_env *new_env);
t_env	*new_env_list(char *value);
void	print_env_list(t_env *env);
t_env	*get_env(char **env);
void	free_env(t_env **env);

//execution
char	*check_path(char *cmd, char **env);
void	exec(char **cmd, t_msh *msh);
void	free_spl(char **env);
void	exec_pipe(t_node *node, t_msh *msh);
void	ms_exec(t_node *node, t_msh *msh);
void	exec_dir(t_node *node, t_msh *msh);
void	exec_main(t_msh *msh);
int		cmd_is_builtin(char **cmd);
void	exec_built(char **cmd, char **env);

//error handling
void	error(void);

//msh_utils
void	free_minishell(t_msh *msh);
int		count_pipe(t_msh *msh);
void	free_node(t_node **node);
void	init_msh(t_msh **msh);
void	check_exit(t_msh *msh);
void	free_all(t_msh *msh);

//parsing
t_node	*parse(t_token *token);
void	print_ast(t_node **node);

//builtin
void	ms_pwd(void);
void	ms_cd(char **cmd, char **env);
void	ms_env(char **env);

#endif