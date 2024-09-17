SRCS			=	src/main.c src/signal_handler.c src/ms_tokenizer.c src/ms_token_utils.c src/env_list.c #src/env.c
OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g# -lreadline

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


.PHONY:			all clean fclean re