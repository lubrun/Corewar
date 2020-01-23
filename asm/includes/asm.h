#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>

typedef struct      s_cmd
{
    struct s_cmd    *next;
    u_int8_t        opc;
}                   t_cmd;

typedef struct      s_file
{
    char            *name;
    char            *comment;
    struct s_header *header;
    struct s_cmd    *list;
    int             fd;
    unsigned char   error;
}                   t_file;


typedef struct      s_option
{
    int             count;
    int             verbose:1;
    int             error:1;
}                   t_option;
int                 parse_header(t_file *file, int fd);
int                 parse_cmd(t_file *file, int fd);
int                 get_prog_name(t_file *file, char **str);
int                 get_prog_comment(t_file *file, char **str);
t_header            *new_header();

#endif