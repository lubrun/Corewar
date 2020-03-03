# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 21:41:29 by qbarrier          #+#    #+#              #
#    Updated: 2020/03/03 20:12:21 by lubrun           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
VM_NAME = corewar
ASM_NAME = asm
PRINTF_NAME = libftprintf.a
SRC_VM_PATH = src_VM/srcs/
SRC_ASM_PATH = src_asm/srcs/
SRC_PRINTFLIB_PATH = libftprintf/srcs/
VM_SRC_NAME =           ft_arguments.c\
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
                        verbose.c 

ASM_SRC_NAME =          main.c \
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
                        write.c
						
PRINTF_SRC_NAME =       big_d_prec_handler.c \
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
                        big_d_prec_handler.c

LIBFTPRINTF_SRC_NAME =  ft_putchar.c \
						ft_putstr.c \
						ft_putendl.c \
						ft_putnbr.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_tolower.c \
						ft_toupper.c \
						ft_isprint.c \
						ft_isascii.c \
						ft_isalpha.c \
						ft_isdigit.c \
						ft_isalnum.c \
						ft_strlen.c \
						ft_strdup.c \
						ft_strcpy.c \
						ft_strncpy.c \
						ft_strcat.c \
						ft_strncat.c \
						ft_strlcat.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strstr.c \
						ft_strnstr.c \
						ft_strcmp.c \
						ft_strncmp.c \
						ft_atoi.c \
						ft_memset.c \
						ft_bzero.c \
						ft_memcpy.c \
						ft_memccpy.c \
						ft_memmove.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memalloc.c \
						ft_memdel.c \
						ft_strnew.c \
						ft_strdel.c \
						ft_strclr.c \
						ft_striter.c \
						ft_striteri.c \
						ft_strmap.c \
						ft_strmapi.c \
						ft_strequ.c \
						ft_strnequ.c \
						ft_strsub.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_strsplit.c \
						ft_buildstr.c \
						ft_count_word.c \
						ft_pow.c \
						ft_itoa.c \
						ft_lstnew.c \
						ft_lstdelone.c \
						ft_lstdel.c \
						ft_lstadd.c \
						ft_lstiter.c \
						ft_lstmap.c \
						ft_lstaddback.c \
						ft_realloc.c \
						ft_index.c \
						get_next_line.c \
						ft_print_2dtab.c \
						ft_2dstrdel.c \
						ft_tablen.c \
						ft_tablenstr.c \
						ft_create_2dtab.c \
						ft_sqrt.c \
						ft_realloc_tab.c \
						ft_nbrlen.c \
						ft_unbrlen.c \
						ft_ulltoa_base.c \
						ft_lltoa_base.c \
						ft_str_toupper.c \
						ft_atoull.c \
						ft_fillnewstr.c \
						ft_newint_tab.c \
						ft_newcoord.c \
						ft_newint_2dtab.c \
						ft_str_isdigit.c \
						ft_2dcontains.c \
						ft_is_empty_line.c \
						ft_get_max.c \
						ft_get_min.c \
						ft_2dinsert.c \
						ft_inttablen.c \
						ft_swap.c \
						ft_count_char.c \
						ft_atoll.c \
                        ft_is_empty_line.c \
                        ft_is_whitespace.c \
                        ft_str_is_whitespace.c \
                        ft_str_isdigit.c
						
SRC_LIB_PATH = libftprintf/libft/

OBJ_PATH = obj/

L_OBJ_PATH = obj/

OBJ_VM = $(VM_SRC_NAME:.c=.o)
    SRC_VM = $(addprefix $(SRC_VM_PATH), $(VM_SRC_NAME))
    OBJ_V = $(addprefix $(OBJ_PATH),$(OBJ_VM))

OBJ_ASM = $(ASM_SRC_NAME:.c=.o)
    SRC_ASM = $(addprefix $(SRC_ASM_PATH), $(ASM_SRC_NAME))
    OBJ_A = $(addprefix $(OBJ_PATH),$(OBJ_ASM))

OBJ_LIBFTPRINTF = $(LIBFTPRINTF_SRC_NAME:.c=.o)
    SRC_L = $(addprefix $(SRC_LIB_PATH), $(LIBFTPRINTF_SRC_NAME))
    OBJ_L = $(addprefix $(L_OBJ_PATH),$(OBJ_LIBFTPRINTF))

OBJ_NAME = $(PRINTF_SRC_NAME:.c=.o)
    SRC_PRINTF = $(addprefix $(SRC_PRINTFLIB_PATH), $(PRINTF_SRC_NAME))
    OBJ_PRINTF = $(addprefix $(L_OBJ_PATH),$(OBJ_NAME))
#ALL_OBJ_NAME = $(OBJ_VM)$(OBJ_ASM)$(OBJ_LIBFTPRINTF)

all: $(PRINTF_NAME) build_vm build_asm

$(PRINTF_NAME) : $(OBJ_PRINTF) $(OBJ_L)
	ar rc $@ $^

$(L_OBJ_PATH)%.o : $(SRC_LIB_PATH)%.c libftprintf/includes/libft.h
	$(CC) $(CFLAGS)  -o $@ -c $<

$(L_OBJ_PATH)%.o : $(SRC_PRINTFLIB_PATH)%.c libftprintf/includes/ft_printf.h
	$(CC) $(CFLAGS)  -o $@ -c $<

build_vm:
	$(CC) $(CFLAGS) -g $(SRC_VM) $(PRINTF_NAME) -o corewar

build_asm:
	$(CC) $(CFLAGS) -g  $(SRC_ASM) $(PRINTF_NAME) -o asm

clean:
	@rm -f $(OBJ_PATH)/*.o
	@echo "\033[32mSuppression .o \t\t==> \tDONE"

fclean: clean
	@rm $(PRINTF_NAME)
	@rm -f asm
	@rm -f corewar
	@echo "\033[32mSuppression .o + .a \t==> \tDONE"

re: fclean all
