/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:16:12 by saandria          #+#    #+#             */
/*   Updated: 2024/09/19 15:09:23 by saandria         ###   ########.fr       */
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

typedef struct s_token		t_token;
typedef enum e_tokentype	t_tokentype;
typedef struct s_env		t_env;

enum	e_tokentype
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIRIN,
	TOK_REDIROUT,
	TOK_APPEND,
	TOK_HEREDOC,
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

//token_utils functions
int		ms_istoken(char c);
void	handle_quotes(char *s, int *i);
void	print_token(t_token *token);
int		ms_isspace(char c);
int		is_in_simple_quotes(char *s, int *i);
int		is_in_double_quotes(char *s, int *i);
void	free_tokens(t_token **t);

//sig_handler
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	ms_signal(void);

//tokenizer
t_token	*ms_tokenizer(char *s);

//environment
//char	**env_copy(char **env);
//void	print_env(char **env);
void	add_env(t_env **env, t_env *new_env);
t_env	*new_env_list(char *value);
void	print_env_list(t_env *env);
t_env	*get_env(char **env);
void	free_env(t_env **env);

#endif