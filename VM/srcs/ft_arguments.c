/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:31:16 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 17:20:29 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_arg_verbose(char **av, t_info *info, int index)
{
	char	*str;
	char	*number;
	int		num;

	if (info->verbose != 0)
		return (ft_error(0, "JUST ONE VERBOSE PLS\n"));
	str = av[index];
	if (!av[index + 1])
		return (ft_error(0, "NEED NUM FOR VERBOSE ARG\n"));
	else
		number = av[index + 1];
	num = ft_atoi(number);
	if (num <= 0 || num > 31)
		return (ft_error(0, "BAD NUM FOR VERBOSE 1-31\n"));
	info->verbose = num;
	return (1);
}

int		ft_arg_dump(char **av, t_info *info, int index)
{
	int		num;
	char	*str;
	char	*number;

	if (info->dump_cycle != -1)
		return (ft_error(0, "JUST ONE DUMP PLS\n"));
	str = av[index];
	if (!av[index + 1])
		return (ft_error(0, "NEED NUM FOR DUMP ARG\n"));
	else
		number = av[index + 1];
	if ((num = ft_atoi(number)) == 0)
		return (ft_error(0, "BAD NUM DUMP\n"));
	if (!ft_strcmp(str, "-d"))
		info->dump_size = 64;
	else
		info->dump_size = 32;
	info->dump_cycle = num;
	return (1);
}

int		ft_put_number_player(int index, char **av, t_info *info)
{
	int	number;

	if (!av[index] || !av[index + 1])
		exit(ft_error(0, "NEED ARGS AFTER -n\n"));
	number = ft_atoi(av[index]);
	if (number <= 0 || number > MAX_PLAYERS || ft_strlen(av[index]) != 1)
		exit(ft_error(0, "BAD NUMBER FOR PLAYER\n"));
	if (info->preset_player[number - 1])
		exit(ft_error(0, "SAME NUMBER FOR PLAYER\n"));
	info->preset_player[number - 1] = index;
	if (!ft_open(av[index + 1], info, number))
		exit(ft_error(0, "BAD FILE 1\n"));
	return (2);
}

int		ft_args_adv(int index, char **av, t_info *info)
{
	if (!ft_strcmp(av[index], "-v") && !ft_arg_verbose(av, info, index))
		return (ft_error(0, "VERBOSE ERROR\n"));
	else if (ft_strcmp(av[index], "-v") && ft_strcmp(av[index], "-a")
			&& !ft_arg_dump(av, info, index))
		return (ft_error(0, "DUMP ERROR\n"));
	return (1);
}

int		ft_arguments(int ac, char **av, t_info *info)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (++index < ac)
	{
		if (!ft_strcmp(av[index], "-d") || !ft_strcmp(av[index], "-dump")
				|| !ft_strcmp(av[index], "-v"))
		{
			count--;
			if (ft_args_adv(index, av, info) == 0)
				return (0);
			index += 1;
		}
		else if (ft_strcmp(av[index], "-n") == 0)
			index += ft_put_number_player(index + 1, av, info);
		else if (ft_strcmp(av[index], "-a") && !ft_open(av[index], info, 0))
			return (ft_error(0, "BAD FILE 2\n"));
		else if (!ft_strcmp(av[index], "-a"))
			info->aff = 1;
		else if (++count > MAX_PLAYERS)
			return (ft_error(0, "TOO MANY ARGS\n"));
	}
	return (1);
}
