/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:51 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/24 19:20:50 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	CHECK FOR AND 6 OR 7 XOR 8
*/

int		ft_check_arg_op_bits(int tab[4], t_chariot *pc)
{
	int index;

	index = -1;
	while (++index < 2)
		if (tab[index] <= 0 || tab[index] > 3)
			return (0);
	if (tab[2] != 1)
		return (0);
	return (ft_size_to_read(tab, 4, pc));
}

/*
**	CHECK FOR ADD 4 SUB 5
*/

int		ft_check_arg_op_addsub(int tab[4], t_chariot *pc)
{
	int index;

	index = -1;
	while (++index < 3)
		if (tab[index] != 1)
			return (0);
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR ST 3
*/

int		ft_check_arg_op_st(int tab[4], t_chariot *pc)
{
	int index;

	index = 1;
	if (tab[0] != 1 || (tab[1] != 1 && tab[1] != 3))
		return (0);
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR LD 2 LLD 13
*/

int		ft_check_arg_op_ld(int tab[4], t_chariot *pc)
{
	int index;

	index = 1;
	if (tab[0] <= 1 || tab[1] != 1)
		return (0);
	return (ft_size_to_read(tab, 4, pc));
}

/*
**	CHECK FOR ZJUMP 9 FORK 12 LFORK 15
*/

int		ft_check_arg_op_jf(int tab[4], t_chariot *pc)
{
	int index;

	index = 0;
	if (tab[0] != 2)
		return (0);
	return (ft_size_to_read(tab, 4, pc));
}
