/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_op2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:56 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/24 19:38:03 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_size_to_read(int tab[4], int direct, t_chariot *pc)
{
	int		index;
	int		octal;
	t_op	*op_tab;

	op_tab = ft_op_tab;
	octal = 0;
	index = -1;
	while (++index < op_tab[pc->op - 1].number_args)
	{
		if (tab[index] == 2)
			pc->tab_jump[index] = direct;
		else if (tab[index] == 3)
			pc->tab_jump[index] = 2;
		else
			pc->tab_jump[index] = tab[index];
		octal += pc->tab_jump[index];
	}
	return (octal);
}

/*
**	CHECK FOR AFF 16
*/

int		ft_check_arg_op_aff(int tab[4], t_chariot *pc)
{
	int index;

	index = 0;
	if (tab[0] != 1)
		return (0);
	return (ft_size_to_read(tab, 0, pc));
}

/*
**	CHECK FOR STI 11
*/

int		ft_check_arg_op_sti(int tab[4], t_chariot *pc)
{
	if (tab[1] < 1 || tab[1] > 3)
		return (0);
	if (tab[2] < 1 || tab[2] > 2 || tab[0] != 1)
		return (0);
	return (ft_size_to_read(tab, 2, pc));
}

/*
**	CHECK FOR LDI 10 LLDI 14
*/

int		ft_check_arg_op_ldi(int tab[4], t_chariot *pc)
{
	if (tab[0] < 1 || tab[0] > 3)
		return (0);
	if (tab[1] < 1 || tab[1] > 2 || tab[2] != 1)
		return (0);
	return (ft_size_to_read(tab, 2, pc));
}

/*
**		LIVE 1
*/

int		ft_check_arg_op_live(int tab[4], t_chariot *pc)
{
	int index;

	index = 0;
	if (tab[0] != 2)
		return (0);
	return (ft_size_to_read(tab, 2, pc));
}
