# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelajour <lelajour@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 21:41:29 by qbarrier          #+#    #+#              #
#    Updated: 2020/03/03 17:45:53 by lelajour         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CFLAGS = -Wall -Werror -Wextra

VM_NAME = corewar

ASM_NAME = asm

PRINTF_NAME = libftprintf.a

LIB_NAME = libftprintf.a

SRC_VM_PATH = ./src_VM/srcs/

H_LIB = ./libftprintf/includes/libft.h

H_PRINTF = ./libftprintf/includes/ft_printf.h

H_ASM = ./src_ASM/includes/op.h ./src_ASM/includes/asm.h

H_VM = ./src_VM/includes/op.h ./src_VM/includes/coreware.h

SRC_ASM_PATH = ./src_ASM/srcs/

SRC_LIB_PATH = ./libftprintf/libft/

SRC_PRINTFLIB_PATH = ./libftprintf/srcs/

VM_SRC_NAME =	\
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
				ft_arguments.c\
						
ASM_SRC_NAME = 			main.c \
						read.c \
						read_name.c \
						read_comment.c \
						read_op.c \
						read_op2.c \
						struct_utils.c \
						struct_utils2.c \
						op.c \
						op_utils.c \
						byte_utils.c \
						write_error.c \
						write.c \
						
PRINTF_SRC_NAME =	big_d_prec_handler.c \
					conversion.c \
					big_d_prec_handler.c \
					flags_prec_handler.c \
					ft_printf.c \
					parser_utils.c \
					parser.c \
					prec_handler.c \
					struct_utils.c \
					u_prec_handler.c \
					width_handler.c \
					x_prec_handler.c \
						
LIBFT_SRC_NAME =	ft_lstclr.c\
						ft_putendl.c\
						ft_strlcat.c\
						ft_lstdel.c\
						ft_putendl_fd.c\
						ft_strlen.c\
						ft_2dstrdel.c\
						ft_lstdelone.c\
						ft_putnbr.c\
						ft_strmap.c\
						ft_atoi.c\
						ft_lstiter.c\
						ft_putnbr_fd.c\
						ft_strmapi.c\
						ft_atoull.c\
						ft_lstlen.c\
						ft_putstr.c\
						ft_strncat.c\
						ft_buildstr.c\
						ft_lstmap.c\
						ft_putstr_fd.c\
						ft_strncmp.c\
						ft_bzero.c\
						ft_lstnew.c\
						ft_realloc.c\
						ft_strncpy.c\
						ft_count_word.c\
						ft_memalloc.c\
						ft_realloc_tab.c\
						ft_strnequ.c\
						ft_create_2dtab.c\
						ft_memccpy.c\
						ft_sqrt.c\
						ft_strnew.c\
						ft_fillnewstr.c\
						ft_memchr.c\
						ft_strnstr.c\
						ft_memcmp.c\
						ft_str_toupper.c\
						ft_strrchr.c\
						ft_memcpy.c\
						ft_strcat.c\
						ft_strsplit.c\
						ft_index.c\
						ft_memdel.c\
						ft_strchr.c\
						ft_strstr.c\
						ft_memmove.c\
						ft_strclr.c\
						ft_strsub.c\
						ft_isalnum.c\
						ft_memset.c\
						ft_strcmp.c\
						ft_strtrim.c\
						ft_isalpha.c\
						ft_nbrlen.c\
						ft_strcpy.c\
						ft_tablen.c\
						ft_isascii.c\
						ft_strdel.c\
						ft_tablenstr.c\
						ft_isdigit.c\
						ft_strdup.c\
						ft_tolower.c\
						ft_isprint.c\
						ft_strequ.c\
						ft_toupper.c\
						ft_itoa.c\
						ft_pow.c\
						ft_strichr.c\
						ft_ulltoa_base.c\
						ft_lltoa_base.c\
						ft_print_2dtab.c\
						ft_striter.c\
						ft_unbrlen.c\
						ft_lstadd.c\
						ft_putchar.c\
						ft_striteri.c\
						get_next_line.c\
						ft_lstaddback.c\
						ft_putchar_fd.c\
						ft_strjoin.c \
						
PATH_PRINTF = $(addprefix $(SRC_PRINTFLIB_PATH), $(PRINTF_SRC_NAME))
	OBJ_PRINTF = $(PATH_PRINTF:.c=.o)

PATH_LIB = $(addprefix $(SRC_LIB_PATH), $(LIBFT_SRC_NAME))
	OBJ_LIB = $(PATH_LIB:.c=.o)
	
PATH_ASM = $(addprefix $(SRC_ASM_PATH), $(ASM_SRC_NAME))
	OBJ_ASM = $(PATH_ASM:.c=.o)
	
PATH_VM = $(addprefix $(SRC_VM_PATH), $(VM_SRC_NAME))
	OBJ_VM = $(PATH_VM:.c=.o)
	
all: $(LIB_NAME) $(PRINTF_NAME) $(VM_NAME) $(ASM_NAME)

$(LIB_NAME): $(OBJ_LIB) $(H_LIB)
	@ar rcs $(LIB_NAME) $(OBJ_LIB)
	@echo "LIB"

$(PRINTF_NAME): $(OBJ_PRINTF) $(OBJ_LIB) $(H_PRINTF)
	@ar rcs $(PRINTF_NAME) $(OBJ_PRINTF) $(OBJ_LIB)
	@echo "LIb + PRINTF"

$(ASM_NAME): $(LIB_NAME) $(OBJ_ASM) $(H_ASM)
	@gcc $(CFLAGS) -o $(OBJ_ASM)
	@echo "ASM"

$(VM_NAME): $(LIB_NAME) $(OBJ_VM) $(H_VM)
	@gcc $(CFLAGS) -o $(OBJ_VM) $(LIB_NAME) $(PRINTF_NAME)
	@echo "VM"	
	
clean:
	@rm -f $(SRC_LIB_PATH)/*.o
	@rm -f $(SRC_ASM_PATH)/*.o
	@rm -f $(SRC_VM_PATH)/*.o
	@rm -f $(SRC_PRINTFLIB_PATH)/*.o
	@echo "\033[32mSuppression .o \t\t==> \tDONE"
	
fclean: clean
	@rm $(PRINTF_NAME)
	@rm -f asm
	@rm -f corewar
	@echo "\033[32mSuppression .o + .a \t==> \tDONE"
	
re: fclean all