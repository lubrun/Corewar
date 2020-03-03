/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_vm2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:24 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:13:07 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	Ecrit dans le r[arg2] la valeur a l'adresse r[arg0] + r[arg1] OP 10
*/

void		ft_ldi(t_info *info, t_chariot *pc)
{
	int	verbose;
	int	res;
	int	moove;

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
	moove = (pc->arg[0] + pc->arg[1]) % IDX_MOD;
	moove = (pc->pos - 2 + moove) % MEM_SIZE;
	res = ft_read_at(info, moove);
	pc->r[pc->arg[2] - 1] = res;
}

/*
** Zjump renvoi le pc->pos a une position, OP 9
*/

void		ft_zjmp(t_info *info, t_chariot *pc)
{
	int	res;

	res = (pc->arg[0]) % IDX_MOD;
	if (pc->carry == 1)
	{
		pc->jump = 0;
		pc->pos = (pc->pos - 1 + res) % MEM_SIZE;
		if (pc->pos < 0)
			pc->pos += MEM_SIZE;
	}
	res = info->verbose;
}

/*
**	Comparation en bits "^" op 8
*/

void		ft_xor(t_info *info, t_chariot *pc)
{
	int	norme;

	norme = info->verbose;
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
	if ((pc->r[pc->arg[2] - 1] = pc->arg[0] ^ pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Comparation en bits "|" op 7
*/

void		ft_or(t_info *info, t_chariot *pc)
{
	int	norme;

	norme = info->verbose;
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
	if ((pc->r[pc->arg[2] - 1] = pc->arg[0] | pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Comparation en bits "&" op 6
*/

void		ft_and(t_info *info, t_chariot *pc)
{
	int	norme;

	norme = info->verbose;
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
	if ((pc->r[pc->arg[2] - 1] = pc->arg[0] & pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}
