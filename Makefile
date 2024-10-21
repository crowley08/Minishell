# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 23:57:27 by arakotom          #+#    #+#              #
#    Updated: 2024/10/21 15:34:20 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g
RDLFLAGS = -lreadline
VGRLFLAGS = valgrind --suppressions=readline.supp --leak-check=full --track-origins=yes --show-leak-kinds=all

SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes
LIBFT_DIR = libft

SRCS = main.c \
		quotes.c \
		signals.c \
		env/init_env.c \
		env/free_env.c \
		msh/init_msh.c \
		msh/free_msh.c \
		msh/err_msh.c \
		heredoc/free_heredoc.c \
		input/init_input.c \
		input/input_utils.c \
		input/input_trim.c \
		input/syntax_validation.c \
		input/err_input.c \
		heredoc/init_heredoc.c \
		heredoc/err_heredoc.c \
		heredoc/free_heredoc.c \
		heredoc/heredoc_expander.c \
		heredoc/heredoc_initializer.c \
		heredoc/heredoc_utils.c \
		heredoc/parser_heredoc.c \
		prompt/free_prompt.c \
		prompt/free_prompt_struct.c \
		prompt/init_prompt.c \
		prompt/prompt_split_pipe.c \
		prompt/prompt_utils.c \
		prompt/prompt_cmd_token.c \
		prompt/prompt_redir_in_token.c \
		prompt/prompt_redir_out_token.c \
		prompt/print_prompt.c \
		execution/init_execute.c \
		execution/execute_utils.c \
		execution/execute_cmd.c \
		execution/execute_set_redir.c \
		execution/execute_list_prompt.c \
		execution/execute_one_prompt.c



OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIB = $(LIBFT_DIR)/libft.a

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

clean :
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re : fclean all

run: $(NAME)
	./$(NAME)

val:$(NAME)
	$(VGRLFLAGS) ./$(NAME)

.PHONY: all clean fclean re
