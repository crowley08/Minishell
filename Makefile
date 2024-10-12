# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 23:57:27 by arakotom          #+#    #+#              #
#    Updated: 2024/10/12 14:42:51 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g
RDLFLAGS = -lreadline
VGRLFLAGS = valgrind --suppressions=readline.supp --leak-check=full --track-origins=yes --show-leak-kinds=all

SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

SRCS = main.c \
		init_msh.c \
		signals.c \
		quote.c \
		env/init_env.c \
		error/error_env.c \
		error/error_input.c \
		error/error_fork.c \
		free/free_env.c \
		free/free_msh.c \
		input/init_input.c \
		input/input_utils.c \
		input/input_trim.c \
		input/launch_syntax_validation.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIB = $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a

RM = rm -rf

NAME = minishell

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@ $(RDLFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(LIB) :
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME)

re : fclean all

run: $(NAME)
	./$(NAME)

valgrind:$(NAME)
	$(VGRLFLAGS) ./$(NAME)

.PHONY: all clean fclean re
