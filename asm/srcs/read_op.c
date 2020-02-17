/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_op.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 16:50:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 23:36:57 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static void reset_op(t_file *file, t_op op)
{
    file->opc_index = file->size;
    file->bytes[file->size++ % CHAMP_MAX_SIZE] = op.id;
    file->opp = 0;
	if (op.acb)
    	file->opp_index = file->size++;
    file->param_index = 0;
}

static int  check_param(t_file *file, t_op op, char **param)
{
    char        *trim;
    t_arg_type  type;
    int         index;

    trim = NULL;
    index = 0;
    reset_op(file, op);
    while (index < op.nb_params)
    {
        if (!param[index])
            return (0);
        if (!(trim = ft_strtrim(param[index])))
            return (-1);
        if ((type = get_param_type(trim, op, index)) < 0)
        {
            printf("WTFFFFFFFFFF\n");
            return (0);
        }
        write_param(file, op, trim, type);
        index++;
        // ft_strdel(&trim);
    }
	if (op.acb)
    	file->bytes[file->opp_index % CHAMP_MAX_SIZE] = file->opp;
    return (1);
}

static int  read_param(t_file *file, char **split, t_op op)
{
    if (!split || !split[0])
        return (0);
    if ((int)ft_tablenstr(split) < op.nb_params)
        return (write_error(file, ft_strdup("Too few args"), 0, 1));
    else if ((int)ft_tablenstr(split) > op.nb_params)
        return (write_error(file, ft_strdup("Too much args"), 0, 1));
    if (!check_param(file, op, split))
        return (write_error(file, ft_strdup("Bad params"), 0, 1));
    return (1);
}

int         is_label(t_file *file, char *str, int *index)
{
    int save;

    save = *index;
    while (str[*index] && ft_strchr(LABEL_CHARS, str[*index]) )
        (*index)++;
    if (*index == save || str[*index] != LABEL_CHAR)
    {
        *index = save;
        return (0);
    }
    if (!new_label(file, ft_strsub(str, 0, *index)))
        return (-1);
    (*index)++;
    while (str[*index] && (str[*index] == ' ' ||
        str[*index] == '\t'))
        (*index)++;
    return (1);
}

int         is_op(t_file *file, char *str)
{
    char    **split;
    char    *tmp;
    t_op    op;
    int     com_index;
    int     ret;
    
    tmp = NULL;
    ret = 0;
    if (!(split = ft_strsplit(str, " \t")))
        return (0);
    if ((op = get_op_by_name(split[0])).id < 0)
        return (write_error(file, ft_strdup("Unknow token"), 0, 1));
    ft_2dstrdel(&split);
    if ((com_index = ft_index(str, '#')) > 0)
        tmp = ft_strsub(str, 0, com_index);
    // printf("[%d]NEW INSTRUCTIONS[%s]\nSET OPC[%d]=[%.2x]\n", file->size, op.name, file->size - 1, op.id);
    if (ft_count_char(((tmp) ? tmp : str), SEPARATOR_CHAR) != op.nb_params - 1)
        ret = write_error(file, ft_strdup("Invalid separator count"), 0, 1);
    else if (read_param(file, ft_strsplit(((!tmp) ? str : tmp) + ft_strlen(op.name), ","), op))
        ret = 1; 
    if (tmp)
        ft_strdel(&tmp);
    return (ret);
}
