/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 10:40:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 23:07:50 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int  get_op(t_file *file, char *str, int start)
{
    int     index;
    int     label;
    int     op;

    index = start;
    if (*(str + index) == '#')
        return (1);
    if ((label = is_label(file, str, &index)) < 0)
        return (0);
    if (label && ft_is_empty_line(str + index))
        return (1);
    if (!(op = is_op(file, str + index)))
        return (0);
    return (1);
}

int         parse_op(t_file *file)
{
    char    *str;
    int     index;
    
    while (get_next_line(file->fd, &str) > 0)
    {
        if (!str)
            return (0);
        file->current_line++;
        if (!(ft_is_empty_line(str)))
        {
            index = 0;
            while (str[index] && (str[index] == ' ' ||
                str[index] == '\t'))
                index++;
            printf("LINE[%s]\n", str + index);
			if (!get_op(file, str, index))
            {
                printf("HERE\n");
                ft_strdel(&str);
                return (0);
            }
        }
        ft_strdel(&str);
    }
    return (1);
}

void        set_magic(t_file *file)
{
    int		magic;

    magic = COREWAR_EXEC_MAGIC;
	swap_four((unsigned int *)&(magic)); 
    file->header.magic = magic;
}

int         parse_header(t_file *file)
{
    char *str;

    file->error = 1;
	ft_bzero(&file->header, sizeof(t_header));
    file->header.magic = 0;
    str = NULL;
    while (!file->header.magic && get_next_line(file->fd, &str))
    {
        if (!str)
            return (0);
        file->current_line++;
        if (!ft_is_empty_line(str))
        {
            if (!ft_strncmp(str, NAME_CMD_STRING, 5) && !get_prog_name(file, &str))
                return (0);
            if (str && !ft_strncmp(str, COMMENT_CMD_STRING, 8) && !get_comment(file, &str))
                return (0);
            if (!file->header.magic && str)
                return (write_error(file, ft_strdup("Incomplete header\n"), 0, 0));
        }
        ft_strdel(&str);
    }
    return (1);
}