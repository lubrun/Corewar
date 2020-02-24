# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 12:06:50 by qbarrier     #+#   ##    ##    #+#        #
#    Updated: 2018/12/03 21:52:27 by qbarrier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
SRC = *.c
SRC_NAME =	ft_strdup.c			\
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
			ft_sqrt.c

NAME = libft.a
HEAD = -I includes/libft.h
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ =  *.o
OBJ_NAME = $(SRC_NAME:.c=.o) 

all : $(NAME)

$(NAME) : $(OBJ_NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)

%.o: %.c
	    @$(CC) $(CFLAGS) $(HEAD) -o $@ -c $< $(FLAGS)

clean :
	@rm -f $(OBJ_NAME)

fclean : clean
	@rm -f $(NAME)

re : fclean all
