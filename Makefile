V_FLAGS			=	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all

SRCS			=	src/main.c src/signal_handler.c parsing/ms_tokenizer.c parsing/ms_tokenizer_utils.c \
					environnement/env_list.c environnement/env.c execution/ms_executor.c utils/msh_utils.c parsing/ms_parser.c \
					utils/free_msh.c execution/ms_executor_utils.c parsing/ms_parser_utils.c \
					builtin/ms_pwd.c builtin/ms_cd.c builtin/ms_env.c 
					
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
