#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <limits.h>

typedef struct      s_label
{
    struct s_label  *next;
    char            *name;
    int             byte_use[255];
    int             use_size[255];
    int             byte_def;
	int				use_count;
}                   t_label;

typedef struct      s_file
{
    struct s_label  *label;
    char			*file_name;
	struct s_header header;
    unsigned char   bytes[CHAMP_MAX_SIZE];
    unsigned char   opp;
    int             opc_index;
    int             opp_index;
    int             param_index;
    int             size;
    int             fd;
    int             new_fd;
    unsigned char   error;
}                   t_file;

typedef struct      s_option
{
    int             count;
    int             verbose:1;
    int             error:1;
}                   t_option;

void				swap_two(unsigned short int *swap);
void				swap_four(unsigned int *swap);
void                write_param(t_file *file, t_op op, char *param, t_arg_type type);
void                write_dir_ind(t_file *file, t_op op, char *param, t_arg_type type);
int                 parse_header(t_file *file);
int                 parse_op(t_file *file);
int                 get_op(t_file *file, char *str, int index);
int                 get_prog_name(t_file *file, char **str);
int                 get_comment(t_file *file, char **str);
int                 new_label(t_file *file, char *label);
int                 is_valid_reg(char *param, int last_param);
int                 is_valid_dir(char *param, int last_param);
int                 is_valid_ind(char *param, int last_param);
int					write_file(t_file *file);
t_op                get_op_by_name(char *name);
int					new_label_use(t_file *file, char *name, int size);
t_arg_type          get_param_type(char *param, t_op op, int index);
t_label				*get_label_by_name(t_label *first, char *name, int use);

#endif