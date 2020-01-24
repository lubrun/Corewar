# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/23 18:30:43 by qbarrier     #+#   ##    ##    #+#        #
#    Updated: 2020/01/23 18:30:55 by qbarrier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = coreware.a
HEAD = -I includes/coreware.h

SRC_PATH = VM/srcs/
SRC_NAME = 

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
	SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

L_NAME = asm/libft/libft.a
L_HEAD = -I asm/libft/libft.h

L_SRC_PATH =	libft/
L_SRC_NAME =	ft_2dcontains.c\
				ft_lstclr.c\
				ft_putendl.c\
				ft_strlcat.c\
				ft_2dinsert.c\
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
				ft_str_isdigit.c\
				ft_strnstr.c\
				ft_get_max.c\
				ft_memcmp.c\
				ft_str_toupper.c\
				ft_strrchr.c\
				ft_get_min.c\
				ft_memcpy.c\
				ft_strcat.c\
				ft_strsplit.c\
				ft_index.c\
				ft_memdel.c\
				ft_strchr.c\
				ft_strstr.c\
				ft_is_empty_line.c\
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
				ft_newcoord.c\
				ft_strdel.c\
				ft_tablenstr.c\
				ft_isdigit.c\
				ft_newint_2dtab.c\
				ft_strdup.c\
				ft_tolower.c\
				ft_isprint.c\
				ft_newint_tab.c\
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
				ft_count_char.c

L_OBJ_PATH = asm/libft/obj/
L_OBJ_NAME = $(L_SRC_NAME:.c=.o)
	L_SRC = $(addprefix $(L_SRC_PATH),$(L_SRC_NAME))
	L_OBJ = $(addprefix $(L_OBJ_PATH),$(L_OBJ_NAME))

all: $(NAME)

$(NAME) : $(OBJ) $(L_OBJ)
	@echo "\033[32mCompilation  \t\t==> \tDONE\033[0m"
	@ar rc $@ $^ 
	@ranlib $@
	@echo "\033[32mlem_in  \t\t==> \tDONE\033[0m"
	@$(CC) $(CFLAGS) $^ -o ./lem-in $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

$(L_OBJ_PATH)%.o: $(L_SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(L_HEAD) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(L_OBJ)
	@echo "\033[32mSuppression .o \t\t==> \tDONE"

fclean: clean
	@rm -f $(NAME) $(L_NAME) ./lem-in
	@echo "\033[32mSuppression .o + .a \t==> \tDONE"

re: fclean all

.PHONY: all, clean, fclean, re
