/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_comment.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 21:04:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:40:26 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int  check_comment_tag(char *str)
{
    char *tmp;

    tmp = str;
    str += 8;
    while (*str && *str == ' ')
        str++;
    if (!*str || *str != '"')
        return (write_error(NULL, ft_strdup("Token expected:.comment \"[comment]\"\n"), 0, 0));
    return (str - tmp);
}

static int  check_comment(char *str, char **name)
{
    int     index;
    int     tmp;

    if ((index = check_comment_tag(str) + 1) == 1)
        return (0);
    tmp = index;
    while (str[index] && str[index] != '"')
        index++;
    if (str[index] != '"' || str[index + 1] != '\0')
        return (write_error(NULL, ft_strdup("Token expected:.comment \"[comment]\"\n"), 0, 0));
    if (index - tmp > PROG_NAME_LENGTH)
        return (write_error(NULL, ft_strdup("Prog_comment too long!\n"), 0, 0));
    if (!(*name = ft_strsub(str, tmp, index - tmp)))
        return (0);
    return (1);
}

int         get_comment(t_file *file, char **str)
{
    char    *comment;
    
    if (file->header.comment[0])
        return (write_error(NULL, ft_strdup("Duplicated token .comment\n"), 0, 0));
    if (!check_comment(*str, &comment))
        return (0);
    ft_memcpy(file->header.comment, comment, ft_strlen(comment));
    ft_strdel(str);
    ft_strdel(&comment);
    if (file->header.prog_name[0])
        set_magic(file);
    return (1);
}