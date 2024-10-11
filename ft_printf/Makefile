# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 17:55:45 by arakotom          #+#    #+#              #
#    Updated: 2024/08/03 00:14:33 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = fpf_putaddress.c \
	fpf_putnbr.c \
	fpf_putchar.c \
	fpf_putstr.c \
	fpf_putnbr_base.c \
	ft_printf.c \
	utils/fpf_strchr.c \
	utils/fpf_strlen.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

RM = rm -rf

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re