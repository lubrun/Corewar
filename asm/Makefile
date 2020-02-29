# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 02:04:28 by lubrun            #+#    #+#              #
#    Updated: 2020/02/29 01:51:47 by lelajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = asm

SRCS = 	srcs/main.c \
		srcs/read.c \
		srcs/read_name.c \
		srcs/read_comment.c \
		srcs/read_op.c \
		srcs/struct_utils.c \
		srcs/op.c \
		srcs/op_utils.c \
		srcs/byte_utils.c \
		srcs/write_error.c \
		srcs/write.c

OBJ = $(SRCS:%.c=%.o)

HEADER = includes

CFLAGS = -Wall -Werror -Wextra -g -Iincludes

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $^ -o $@

%.o : %.c includes/asm.h
	@echo "bonjour asm"
	@gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re:	fclean all

norm:
	norminette srcs/*.c $(HEADER)/*.h libft/*.c libft/*.h

.PHONY: all clean fclean re
