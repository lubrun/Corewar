/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_op.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 16:50:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 09:54:12 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int  check_param(t_file *file, t_op op, char **param)
{
    int         index;
    // int         opc_index;
    t_arg_type  type;

    index = 0;
    file->opp = 0;
	if (op.acb)
    	file->opp_index = file->size++;
    file->param_index = 0;
    while (index < op.nb_params)
    {
        if (param[index][ft_strlen(param[index]) - 1] != SEPARATOR_CHAR  && index != op.nb_params - 1)
        {
            write(1, "Missing separator\n", 18);
            return (0);
        }
        // printf("CHECK PARAM[%d][%s]\n", index, param[index]);
        if ((type = get_param_type(param[index], op, index)) < 0) 
            return (0);
        write_param(file, op, param[index], type);
        index++;
    }
	if (op.acb)
    	file->bytes[file->opp_index] = file->opp;
	// printf("SET OPP[%d]=%.2x\n", file->opp_index, file->opp);
    return (1);
}

static int  is_label(t_file *file, char *str, int *index)
{
    int save;

    save = *index;
    while (str[*index] && ft_strchr(LABEL_CHARS, str[*index]))
        (*index)++;
    if (index == 0 || str[*index] != LABEL_CHAR)
    {
        *index = save;
        return (-1);
    }
    if (!new_label(file, ft_strsub(str, 0, *index)))
        return (0);
    (*index)++;
    while (str[*index] && (str[*index] == ' ' ||
        str[*index] == '\t'))
        (*index)++;
    return (1);
}

static int  is_op(t_file *file, char **split)
{
    t_op    op;
    int     index;
    
    index = 0;
    if (!(op = get_op_by_name(split[index])).id)
    {
        write(1, "Unknow token\n", 13);
        return (0);
    }
	file->opc_index = file->size;
    file->bytes[file->size++] = op.id;
    // printf("[%d]NEW INSTRUCTIONS[%s]\nSET OPC[%d]=[%.2x]\n", file->size, op.name, file->size - 1, op.id);
    if ((int)ft_tablenstr(split) - 1 != op.nb_params ||
    ((int)ft_tablenstr(split) - 1 > op.nb_params && split[op.nb_params + 1][0] == COMMENT_CHAR) ||
        !check_param(file, op, split + 1))
    {
        write(1, "Bad param(s)\n", 13);
        return (0);
    }
    return (1);
}

int         get_op(t_file *file, char *str, int start)
{
    char    **split;
    int     index;

    index = start;
    if (!is_label(file, str, &index) ||
        !(split = ft_strsplit(str + index, ' ')) || !is_op(file, split))
            return (0);
        index++;
    return (1);
}