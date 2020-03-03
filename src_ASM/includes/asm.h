/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:51:37 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:57:24 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libftprintf/includes/ft_printf.h"
# include "op.h"
# include "fcntl.h"
# include <limits.h>

typedef struct		s_label
{
	struct s_label	*next;
	char			*name;
	int				opc_index[255];
	int				byte_use[255];
	int				use_line[255];
	int				use_size[255];
	int				byte_def;
	int				use_count;
}					t_label;

typedef struct		s_file
{
	struct s_label	*label;
	struct s_label	*error_label;
	char			*file_name;
	struct s_header	header;
	unsigned char	bytes[CHAMP_MAX_SIZE];
	int				current_line;
	int				opc_index;
	int				opp_index;
	int				param_index;
	int				size;
	int				fd;
	int				new_fd;
	unsigned char	opp;
	unsigned char	error;
}					t_file;

void				free_file(t_file *file);
void				print_asm(t_file *file);
void				set_magic(t_file *file);
void				swap_two(unsigned short int *swap);
void				swap_four(unsigned int *swap);
int					write_param(t_file *file, t_op op, char *param,
	t_arg_type type);
int					write_dir_ind(t_file *file, t_op op, char *param,
	t_arg_type type);
int					parse_header(t_file *file);
int					parse_op(t_file *file);
int					get_prog_name(t_file *file, char **str);
int					get_comment(t_file *file, char **str);
int					is_label(t_file *file, char *str, int *index);
int					is_valid_op(t_file *file, t_op *op, char *str, int label);
int					is_op(t_file *file, char *str, int label);
int					new_label(t_file *file, char *label, int free);
int					write_file(t_file *file);
int					new_label_use(t_file *file, char *name, int size);
int					check_error(t_file *file);
int					write_error(t_file *file, char *to_write, int ret,
	int line);
t_op				get_op_by_name(char *name);
t_arg_type			get_param_type(char *param, t_op op, int index);
t_label				*get_label_by_name(t_label *first, char *name, int use);
char				*insert_token_error(char **split);
char				*get_output_name(char *name);
#endif
