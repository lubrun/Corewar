/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:46:31 by lubrun            #+#    #+#             */
/*   Updated: 2020/02/29 01:44:50 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_asm_file(char *name)
{
	int index;

	index = 0;
	while (name[index])
		index++;
	if (name[index - 1] != 's' || name[index - 2] != '.')
		return (0);
	return (1);
}

static int	print_error(int code, char *name)
{
	if (code == 0)
		write(1, "syntax error: ./asm [file.s][file1.s]...\n", 41);
	else if (code == 1)
		write(1, "Can't write output file\n", 24);
	if (name)
		unlink(name);
	return (0);
}

static int	parse_arg(int ac, char **av)
{
	if (ac == 1)
		return (print_error(0, NULL));
	if (ac == 2)
	{
		if (av[1] && !is_asm_file(av[1]))
		{
			write(1, "Only .s file accepted\n", 22);
			return (0);
		}
	}
	return (1);
}

static int	parse_file(int ac, char **av)
{
	t_file	*file;
	int		index;

	index = 1;
	while (index < ac)
	{
		if (!(file = ft_memalloc(sizeof(t_file))))
			return (0);
		ft_bzero(file, sizeof(t_file));
		if (!is_asm_file(av[index]))
			return (print_error(2, NULL));
		if ((file->fd = open(av[index], O_RDONLY)) == -1 ||
		!(file->file_name = ft_strdup(av[index])))
			return (print_error(1, get_output_name(av[index])));
		if (!parse_header(file) || !parse_op(file) || !write_file(file))
			return (print_error(file->error, get_output_name(av[index])));
		index++;
		free_file(file);
	}
	return (1);
}

int				main(int ac, char **av)
{
	if (!parse_arg(ac, av) || !parse_file(ac, av))
		return (0);
	return (1);
}
