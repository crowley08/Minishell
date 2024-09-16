/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:16:12 by saandria          #+#    #+#             */
/*   Updated: 2024/09/16 14:56:34 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h" 
# include <term.h>

typedef struct	s_token	t_token;
typedef enum	e_tokentype	t_tokentype;

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
	t_tokentype	type;
	char        *value;
	t_token        *next;
};

//sig_handler
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	ms_signal(void);

#endif