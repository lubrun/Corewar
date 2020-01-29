/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_comment.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 21:04:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 09:46:42 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int  check_comment_tag(char *str)
{
    char *tmp;

    tmp = str;
    str += 9;
    while (*str && *str == ' ')
        str++;
    if (!*str || *str != '"')
    {
        write(1, "Token expected:.comment \"[comment]\"\n", 37);
        return (0);
    }
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
    {
        write(1, "Token expected:.comment \"[comment]\"\n", 27);
        return (0);
    }
    if (index - tmp > PROG_NAME_LENGTH)
    {
        write(1, "Prog_comment too long!\n", 21);
        return (0);
    }
    if (!(*name = ft_strsub(str, tmp, index - tmp)))
        return (0);
    return (1);
}

int         get_comment(t_file *file, char **str)
{
    char    *comment;
	int		magic;

    if (file->header.comment[0])
    {
        write(1, "Duplicated token .comment\n", 27);
        return (0);
    }
    if (!check_comment(*str, &comment))
    {
        write(1, "Prog_comment bad format!\n", 26);
        return (0);
    }
    ft_memcpy(file->header.comment, comment, ft_strlen(comment));
    magic = COREWAR_EXEC_MAGIC;
	swap_four((unsigned int *)&(magic)); 
	file->header.magic = magic;
    ft_strdel(str);
    ft_strdel(&comment);
    return (1);
}