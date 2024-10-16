V_FLAGS			=	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all

SRCS			=	src/main.c src/signal_handler.c environnement/env_list.c environnement/env.c execution/ms_executor.c utils/msh_utils.c \
					utils/free_msh.c execution/ms_executor_utils.c builtin/ms_pwd.c builtin/ms_cd.c builtin/ms_env.c \
					parsing/ast/ms_parser_utils.c parsing/ast/ms_parser.c parsing/tokenizer/ms_tokenizer_utils.c parsing/tokenizer/ms_tokenizer.c \
					parsing/input/heredoc/create_heredoc.c parsing/input/heredoc/free_heredoc.c parsing/input/heredoc/heredoc_error.c \
					parsing/input/heredoc/heredoc_expand.c parsing/input/heredoc/heredoc_input.c parsing/input/heredoc/heredoc_sig.c \
					parsing/input/heredoc/parse_heredoc.c parsing/input/heredoc/tmp_file.c parsing/input/quotes/parse_quotes_utils.c \
					parsing/input/quotes/parse_quotes.c parsing/input/free_parse.c parsing/input/parse_and_trim.c parsing/input/parse_input_error.c \
					parsing/input/parse_input_syntax.c parsing/input/parse_input_utils.c parsing/input/parse_input.c parsing/input/parse_redir.c \
					parsing/input/syntax_error.c execution/ms_exec_redir_out_utils.c execution/ms_exec_redir_out.c execution/ms_exec_redir_in.c \

OBJS			=	$(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= minishell


all:			$(NAME)

$(NAME):		$(OBJS)
				cd libft && make
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lreadline

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				cd libft && make clean
				$(RM) $(OBJS)

fclean:			clean
				cd libft && make fclean
				$(RM) $(NAME)

re:				fclean all 

valgrind:		re
				$(V_FLAGS) ./$(NAME)

.PHONY:			all clean fclean re