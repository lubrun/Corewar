/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_name.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 21:04:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 16:53:11 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int  check_name_tag(char *str)
{
    char *tmp;

    tmp = str;
    str += 5;
    while (*str && *str == ' ')
        str++;
    if (!*str || *str != '"')
    {
        write(1, "Token expected:.name \"[NAME]\"\n", 31);
        return (0);
    }
    return (str - tmp);
}

static int  check_prog_name(char *str, char **name)
{
    int     index;
    int     tmp;

    if ((index = check_name_tag(str) + 1) == 1)
        return (0);
    tmp = index;
    while (str[index] && str[index] != '"')
        index++;
    if (str[index] != '"' || str[index + 1] != '\0')
    {
        write(1, "Token expected:.name \"[NAME]\"\n", 31);
        return (0);
    }
    if (index - tmp > PROG_NAME_LENGTH)
    {
        write(1, "Prog_name too long!\n", 21);
        return (0);
    }
    if (!(*name = ft_strsub(str, tmp, index - tmp)))
        return (0);
    return (1);
}

int         get_prog_name(t_file *file, char **str)
{
    char    *name;

    if (file->header->prog_name[0])
    {
        write(1, "Duplicated token .name\n", 24);
        return (0);
    }
    if (!check_prog_name(*str, &name))
    {
        write(1, "Prog_name bad format!\n", 23);
        return (0);
    }
    ft_memcpy(file->header->prog_name, name, ft_strlen(name));
    ft_strdel(str);
    ft_strdel(&name);
    return (1);
}