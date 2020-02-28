/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:25 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/28 19:27:39 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void reset_op(t_file **afile, t_op op)
{
    t_file  *file;

    file = *afile;
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
    while (index < op.nb_params)
    {
        if (!param[index])
            return (0);
        if (!(trim = ft_strtrim(param[index])))
            return (-1);
        if (!(type = get_param_type(trim, op, index)))
		    return (0);
		if (!write_param(file, op, trim, type))
			return (0);
        index++;
        ft_strdel(&trim);
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
    {
        ft_2dstrdel(&split);
        return (write_error(file, ft_strdup("Too few args"), 0, 1));
    }
    else if ((int)ft_tablenstr(split) > op.nb_params)
    {
        ft_2dstrdel(&split);
        return (write_error(file, ft_strdup("Too much args"), 0, 1));
    }
    if (!check_param(file, op, split))
    {
        ft_2dstrdel(&split);
        return (write_error(file, ft_strdup("Bad params"), 0, 1));
    }
    ft_2dstrdel(&split);
    return (1);
}

int         is_label(t_file *file, char *str, int *index)
{
    char    *sub;
    int     save;

    save = *index;
    sub = ((ft_strchr(str, COMMENT_CHAR) ? ft_strsub(str, *index, ft_index(str, COMMENT_CHAR) - *index - 1) : str));
    if (!sub)
        return (-1);
    while (sub[*index] && ft_strchr(LABEL_CHARS, sub[*index]))
        (*index)++;
    if (*index == save || sub[*index] != LABEL_CHAR)
    {
        if (str != sub)
            ft_strdel(&sub);
        *index = save;
        return (0);
    }
    if (!new_label(file, ft_strsub(sub, save, *index)))
        return (-1);
    (*index)++;
    while (sub[*index] && (sub[*index] == ' ' ||
        sub[*index] == '\t'))
        (*index)++;
    if (str != sub)
            ft_strdel(&sub);
    return (1);
}

int         is_op(t_file *file, char *str, int label)
{
    char    *tmp;
    t_op    op;
    int     com_index;
    int     ret;
    
    tmp = NULL;
    if ((com_index = ft_index(str, '#')) > 0)
        tmp = ft_strsub(str, 0, com_index);
	if (!(ret = is_valid_op(file, &op, (tmp) ? tmp : str, label)))
        return (0);
	else if (ret == -1)
		return (1);
    reset_op(&file, op);
    ret = 0;
    if (ft_count_char(((tmp) ? tmp : str), SEPARATOR_CHAR) != op.nb_params - 1)
        ret = write_error(file, ft_strdup("Invalid separator count"), 0, 1);
    else if (read_param(file, ft_strsplit(((!tmp) ? str : tmp) + ft_strlen(op.name), ","), op))
        ret = 1;
    if (tmp)
        ft_strdel(&tmp);
    return (ret);
}
