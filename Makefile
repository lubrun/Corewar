# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:30:43 by qbarrier          #+#    #+#              #
#    Updated: 2020/02/25 15:39:47 by lelajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = corewar.a

SRC_PATH = VM/srcs/
SRC_LIBFT_PATH = asm/libft/
SRC_PRINTFLIB_PATH = libftprintf/

L_SRC_NAME =	ft_arguments.c\
				ft_build_chariot.c\
				ft_build_map.c\
				ft_check_args_op.c\
				ft_check_args_op2.c\
				ft_ctox.c\
				ft_display.c\
				ft_error.c\
				ft_fonctions_vm.c\
				ft_fonctions_vm2.c\
				ft_fonctions_vm3.c\
				ft_fonctions_vm4.c\
				ft_free_all.c\
				ft_parcour_map.c\
				ft_parsing_code.c\
				ft_parsing.c\
				ft_read_arguments_opc.c\
				main.c\
				op.c\
				struct_utils.c\
				struct_utils2.c\
				struct_utils3.c\
				struct_utils4.c\
				struct_utils5.c\
				verbose.c \

L_PRINTF = libftprintf.a \

L_LIBFT = libft.a \

OBJ_SRC = $(addprefix $(SRC_PATH), $(L_SRC_NAME))

OBJ_LIBFT = $(addprefix $(SRC_LIBFT_PATH), $(L_LIBFT))

OBJ_PRINTFLIB = $(addprefix $(SRC_PRINTFLIB_PATH), $(L_PRINTF))

L_OBJ_PATH = asm/libft/

all: $(NAME)

$(NAME) : $(OBJ) $(L_OBJ)
	@echo "\033[32mCompilation  \t\t==> \tDONE\033[0m"
	@make -C asm
	@make -C libftprintf
	@mv asm/asm asm_exec
	@$(CC) $(CFLAGS) $^ -o $(NAME) $(OBJ_SRC) $(OBJ_LIBFT) $(OBJ_PRINTFLIB)
	@echo "\033[32mCorewar  \t\t==> \tDONE\033[0m"
./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[0;32m✅️    $@ created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

clean:
	@make clean -C asm/libft
	@make clean -C libftprintf
	@rm -f $(OBJ) $(L_OBJ)
	@rm -f asm_exec
	@echo "\033[32mSuppression .o \t\t==> \tDONE"

fclean: clean
	@rm -f asm/libft/libft.a
	@rm -f libftprintf/libftprintf.a
	@rm -f corewar.a
	@echo "\033[32mSuppression .o + .a \t==> \tDONE"

re: fclean all
