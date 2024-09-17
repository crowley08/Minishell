SRCS			=	src/main.c src/signal_handler.c src/ms_tokenizer.c src/ms_token_utils.c src/env.c
OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -lreadline

NAME			= minishell

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)
$(NAME):
				cd libft && make
				$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
				cd libft && make clean
				$(RM) $(OBJS)

fclean:			clean
				cd libft && make fclean
				$(RM) $(NAME)

re:				fclean all 


.PHONY:			all clean fclean re