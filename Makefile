# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 23:57:27 by arakotom          #+#    #+#              #
#    Updated: 2024/10/07 11:21:28 by arakotom         ###   ########.fr        #
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
		quote_utils.c \
		data_utils.c \
		envp/envp_utils.c \
		envp/init_envp.c \
		input/init_input.c \
		input/input_trim.c \
		input/input_utils.c \
		input/input_validation.c \
		input/input_expander_dequote.c \
		input/redir_heredoc/redir_validation.c \
		input/redir_heredoc/init_heredoc.c \
		input/redir_heredoc/heredoc_utils.c \
		input/redir_heredoc/heredoc_input_parse.c \
		input/redir_heredoc/heredoc_input_parse_utils.c \
		prompt/init_prompt.c \
		prompt/prompt_utils.c \
		prompt/prompt_split.c \
		prompt/free/free_struct.c \
		prompt/free/free_struct_utils.c

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
