# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/03 19:36:27 by qbarrier     #+#   ##    ##    #+#        #
#    Updated: 2018/12/18 15:56:12 by qbarrier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
HEAD = -I include/printf.h

SRC_PATH = src/
SRC_NAME = 		ft_printf.c				\
				ft_read_printf.c		\
				ft_parse.c				\
				ft_str_isconvert.c		\
				ft_datanew.c			\
				ft_displaynew.c			\
				ft_is_attribute.c		\
				ft_make_strconvert_d.c	\
				ft_make_strconvert_c.c	\
				ft_make_strconvert_p.c	\
				ft_make_strconvert_s.c	\
				ft_make_strconvert_x.c	\
				ft_make_strconvert_o.c	\
				ft_make_strconvert_u.c	\
				ft_make_strconvert_f.c	\
				ft_make_strconvert_pc.c	\
				ft_trans_floatation.c	\
				ft_lstdel_str.c			\
				ft_choose_params.c




OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
	SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

L_NAME = libft/libft.a
L_HEAD = -I libft/libft.h

L_SRC_PATH =	libft/
L_SRC_NAME =	ft_strdup.c			\
				ft_strlen.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_atol.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_strpresplit.c	\
				ft_countword.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_istvnrf.c		\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_dellist.c		\
				ft_strupcase.c		\
				ft_strlowcase.c		\
				get_next_line.c		\
				ft_sqrt.c			\
				ft_strnadd.c		\
				ft_str_endcpy.c		\
				ft_itoa_base.c		\
				ft_ulltoa_base.c	\
				ft_strfadd.c

L_OBJ_PATH = libft/obj/
L_OBJ_NAME = $(L_SRC_NAME:.c=.o)
	L_SRC = $(addprefix $(L_SRC_PATH),$(L_SRC_NAME))
	L_OBJ = $(addprefix $(L_OBJ_PATH),$(L_OBJ_NAME))






all: $(NAME)

$(NAME) : $(OBJ) $(L_OBJ)
	@echo "\033[32mCompilation  \t\t==> \tDONE\033[0m"
	@ar rc $@ $^ 
	@ranlib $@
	@echo "\033[32mPRINTF.A  \t\t==> \tDONE\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

$(L_OBJ_PATH)%.o: $(L_SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(L_HEAD) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(L_OBJ)
	@echo "\033[32mSuppression .o \t\t==> \tDONE"

fclean: clean
	@rm -f $(NAME) $(L_NAME)
	@echo "\033[32mSuppression .o + .a \t==> \tDONE"

re: fclean all

.PHONY: all, clean, fclean, re
