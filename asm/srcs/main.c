/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 21:46:31 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 09:53:43 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int          is_asm_file(char *name)
{
    int index;

    index = 0;
    while (name[index])
        index++;
    if (name[index - 1] != 's' || name[index - 2] != '.')
        return (0);
    return (1);
}

static t_option     parse_option(int ac, char **av)
{
    int         index;

    index = 1;
    while (index < ac)
    {
        if (av[index][0] != '-')
            return ((t_option){0, -1, -1});
        if (av[index][1] == 'a')
            return ((t_option){1, 1, 0});
        index++;
    }
    return ((t_option){0, -1, -1});
}

static t_option     print_error(int code)
{
    if (code == 0)
        write(1, "syntax error: ./asm [file.s][file1.s]...\noption:\n\t-a\tFor verbose\n", 66);
    else if (code == 1)
        write(1, "Invalid file\n", 14);
    return ((t_option){0, -1, 1});
}

static t_option     parse_arg(int ac, char **av)
{
    t_option option;

    if (ac <= 2)
    {
        if (is_asm_file(av[1]))
            return ((t_option){0, 0, 0});
        if (av[1] && ft_strcmp(av[1], "-help"))
        {
            write(1, "Syntax: ./asm -help\n", 21);
            return ((t_option){-1, -1, 1});
        }
    }
    if ((option = parse_option(ac, av)).error)
        return ((t_option){-1, -1, 1});
    return (option);
}

static int      parse_file(int ac, char **av, t_option opt)
{
    t_file	*file;
    int		index;

    index = opt.count + 1;
    while (index < ac)
    {
		if (!(file = ft_memalloc(sizeof(t_file))))
			return (0);
	    ft_bzero(file, sizeof(t_file));
		if (!is_asm_file(av[index]) || (file->fd = open(av[index], O_RDONLY)) == -1 ||
			!(file->file_name = ft_strdup(av[index])))
            return (print_error(1).count);
        if (!parse_header(file) || !parse_op(file) ||
			!write_file(file))
            return (print_error(file->error).count);
		index++;
    }
    return (1);
}

int              main(int ac, char **av)
{
    t_option    opt;

    if ((opt = parse_arg(ac, av)).error ||
        !parse_file(ac, av, opt))
        return (opt.error);
    return (1);
}