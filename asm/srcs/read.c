/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 10:40:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 08:33:04 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int         parse_op(t_file *file)
{
    char    *str;
    int     index;
    
    while (get_next_line(file->fd, &str) > 0)
    {
        if (!str)
            return (0);
        if (!(ft_is_empty_line(str)))
        {
            index = 0;
            while (str[index] && (str[index] == ' ' ||
                str[index] == '\t'))
                index++;
			if (!get_op(file, str, index))
            {
                ft_strdel(&str);
                return (0);
            }
        }
        ft_strdel(&str);
    }
    return (1);
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
        if (!ft_is_empty_line(str))
        {
            if (!ft_strncmp(str, NAME_CMD_STRING, 5) && !get_prog_name(file, &str))
                return (0);
            else if (str && !ft_strncmp(str, COMMENT_CMD_STRING, 8) && !get_comment(file, &str))
                return (0);
            else if (str)
                return (0);
        }
        ft_strdel(&str);
    }
    return (1);
}