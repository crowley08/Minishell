V_FLAGS			=	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all

SRCS			=	src/main.c src/signal_handler.c parsing/tokenizer/ms_tokenizer.c parsing/tokenizer/ms_tokenizer_utils.c \
					environnement/env_list.c environnement/env.c execution/ms_executor.c utils/msh_utils.c parsing/ast/ms_parser.c \
					utils/free_msh.c execution/ms_executor_utils.c parsing/ast/ms_parser_utils.c \
					builtin/ms_pwd.c builtin/ms_cd.c builtin/ms_env.c \
					parsing/input_parse/input_handler.c parsing/input_parse/parse_input.c parsing/input_parse/check_input_utils.c \
					parsing/input_parse/check_input.c parsing/input_parse/input_expander.c parsing/input_parse/quotes_utils.c \
					parsing/input_parse/redir_utils.c parsing/input_parse/trim_utils.c parsing/input_parse/heredoc/free_heredoc.c \
					parsing/input_parse/heredoc/heredoc_utils.c parsing/input_parse/heredoc/heredoc.c parsing/input_parse/heredoc/init_heredoc.c \
					
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
