/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_vm3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:35 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:12:34 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
** Creait un nouveau PC copie de l'actuel a la position pos + (arg[0]) OP 15
*/

void		ft_lfork(t_info *info, t_chariot *pc)
{
	int			moove;
	t_chariot	*new;

	moove = (pc->pos - 1 + (pc->arg[0])) % MEM_SIZE;
	if (moove < 0)
		moove += MEM_SIZE;
	new = ft_new_chariot(pc->player, moove, info);
	ft_pc_cpy(new, pc);
	ft_add_first_chariot(&info->chariot, new);
}

/*
**	Ecrit dans le r[arg2] la valeur a l'adresse r[arg0] + r[arg1] OP 14
**	on utilise IDX_MOD pour chercher l'IND
*/

void		ft_lldi(t_info *info, t_chariot *pc)
{
	int verbose;
	int moove;

	verbose = info->verbose;
	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	else if (pc->type_arg[0] == 3)
		pc->arg[0] = ft_read_at(info, (pc->pos - 2 + (pc->arg[0] % IDX_MOD))
				% MEM_SIZE);
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	else if (pc->type_arg[1] == 3)
		pc->arg[1] = ft_read_at(info, (pc->pos - 2 + (pc->arg[1] % IDX_MOD))
				% MEM_SIZE);
	moove = (pc->arg[0] + pc->arg[1]);
	moove = (pc->pos - 2 + moove) % MEM_SIZE;
	if (moove < 0)
		moove += MEM_SIZE;
	pc->r[pc->arg[2] - 1] = ft_read_at(info, moove);
	if (pc->r[pc->arg[2] - 1] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Ecrit arg[1] dans le registre r[arg[0] - 1]
** mais sans idx (cf ft_indirect_arg) OP 13
*/

void		ft_lld(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	if (pc->type_arg[0] == 3)
		pc->arg[0] = ft_read_at(info, (pc->pos - 2 + pc->arg[0]) % MEM_SIZE);
	if (pc->arg[0] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->r[pc->arg[1] - 1] = pc->arg[0];
}

/*
** Creait un nouveau PC copie de l'actuel a la position pos +
** (arg[0] % IDX) OP 12
*/

void		ft_fork(t_info *info, t_chariot *pc)
{
	int			moove;
	t_chariot	*new;

	moove = (pc->pos - 1 + (pc->arg[0] % IDX_MOD)) % MEM_SIZE;
	if (moove < 0)
		moove += MEM_SIZE;
	new = ft_new_chariot(pc->player, moove, info);
	ft_pc_cpy(new, pc);
	ft_add_first_chariot(&info->chariot, new);
}

/*
**	ECRIT LA VALEUR CONTENUE DANS r[ARG[0]] Sur REG_SIZE octet DANS
**	(arg1 +arg2) % IDX_MOD DEPUIS L'OP (d'ou le -2 pour moove) OP 11
*/

void		ft_sti(t_info *info, t_chariot *pc)
{
	int	moove;
	int	val;
	int	index;
	int	reg;

	reg = pc->arg[0];
	index = 0;
	while (index < 3)
	{
		if (pc->type_arg[index] == 1)
			pc->arg[index] = pc->r[pc->arg[index] - 1];
		else if (pc->type_arg[index] == 3)
			pc->arg[index] = ft_read_at(info,
					(pc->pos - 2 + (pc->arg[index] % IDX_MOD)) % MEM_SIZE);
		index++;
	}
	val = pc->arg[0];
	moove = (pc->arg[1] + pc->arg[2]) % IDX_MOD;
	moove = (moove + (pc->pos - 2)) % MEM_SIZE;
	if (moove < 0)
		moove += MEM_SIZE;
	ft_write_on_map(info, val, moove, REG_SIZE);
}
