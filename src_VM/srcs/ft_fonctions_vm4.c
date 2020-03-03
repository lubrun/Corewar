/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_vm4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:40 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:11:56 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	Affiche l'arg[0] en CHAR si -a     OP 16
*/

void		ft_aff(t_info *info, t_chariot *pc)
{
	if (info->aff == 1)
	{
		ft_putstr("Aff: ");
		ft_putchar((char)pc->r[pc->arg[0] - 1]);
		ft_putchar('\n');
	}
}

/*
**	Les 16 fonction selon l'OP - 1.
*/

void		ft_add_vm_fonction(t_info *info)
{
	info->fonction_op[0] = ft_live;
	info->fonction_op[1] = ft_ld;
	info->fonction_op[2] = ft_st;
	info->fonction_op[3] = ft_add;
	info->fonction_op[4] = ft_sub;
	info->fonction_op[5] = ft_and;
	info->fonction_op[6] = ft_or;
	info->fonction_op[7] = ft_xor;
	info->fonction_op[8] = ft_zjmp;
	info->fonction_op[9] = ft_ldi;
	info->fonction_op[10] = ft_sti;
	info->fonction_op[11] = ft_fork;
	info->fonction_op[12] = ft_lld;
	info->fonction_op[13] = ft_lldi;
	info->fonction_op[14] = ft_lfork;
	info->fonction_op[15] = ft_aff;
}
