/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 10:40:32 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 17:06:21 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int     parse_cmd(t_file *file, int fd)
{
    char    *str;
    int     index;

    while (get_next_line(fd, &str) > 0)
    {
        if (!str)
            return (0);
        index = 0;
        if (!(ft_is_empty_line(str)))
        {
        }
        ft_strdel(&str);
    }
    return (1);
}

int     parse_header(t_file *file, int fd)
{
    char *str;

    file->error = 1;
    if (!(file->header = new_header()))
        return (0);
    file->header->magic = 0;
    while (!file->header->magic && get_next_line(fd, &str))
    {
        if (!str)
            return (0);
        if (!ft_is_empty_line(str))
        {
            if (!ft_strncmp(str, NAME_CMD_STRING, 5) && !get_prog_name(file, &str))
                return (0);
            else if (str && !ft_strncmp(str, COMMENT_CMD_STRING, 8) && !get_prog_comment(file, &str))
                return (0);
            else if (str)
                return (0);
        }
        ft_strdel(&str);
    }
    return (1);
}