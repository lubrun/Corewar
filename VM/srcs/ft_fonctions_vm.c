/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:18 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:11:24 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	r[arg2 - 1] =r[arg0 - 1] - r[arg1 - 1] OP 4
*/

void		ft_sub(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	pc->arg[0] = pc->r[pc->arg[0] - 1];
	pc->arg[1] = pc->r[pc->arg[1] - 1];
	if ((pc->r[pc->arg[2] - 1] = pc->arg[0] - pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	r[arg2 - 1] =r[arg0 - 1] + r[arg1 - 1] OP 4
*/

void		ft_add(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	pc->arg[0] = pc->r[pc->arg[0] - 1];
	pc->arg[1] = pc->r[pc->arg[1] - 1];
	if ((pc->r[pc->arg[2] - 1] = pc->arg[0] + pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Ecrit r[arg[0] - 1] dans r[arg[1] - 1]
**	ou a la postition pos + (arg[1] % IDX) -2 OP 3
*/

void		ft_st(t_info *info, t_chariot *pc)
{
	int moove;

	pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
	{
		pc->r[pc->arg[1] - 1] = pc->arg[0];
	}
	else
	{
		moove = ((pc->arg[1]) % IDX_MOD) % MEM_SIZE;
		ft_write_on_map(info, pc->arg[0], (moove + pc->pos - 2) %
				MEM_SIZE, REG_SIZE);
	}
}

/*
**	Ecrit arg[1] dans le registre r[arg[0] - 1] OP 2
*/

void		ft_ld(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	if (pc->type_arg[0] == 3)
		pc->arg[0] = ft_read_at(info, (pc->pos - 2 +
					(pc->arg[0] % IDX_MOD)) % MEM_SIZE);
	if (pc->arg[0] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->r[pc->arg[1] - 1] = pc->arg[0];
}

/*
**	augmente le compteur de LIVE dans le pc et le compteur total
**	Si arg[0] correspond a un joueur mais en negatif (-1) le joueur 1
**	sera en vie a cet instantOP 1
*/

void		ft_live(t_info *info, t_chariot *pc)
{
	t_player *play;

	pc->cycle_live++;
	pc->last_live = 0;
	info->live_total++;
	if ((play = ft_player_by_id(info->play, (pc->arg[0] * -1))))
	{
		if (check_bit(info->verbose, 0) != 0)
			printf("Player %d (%s) is said to be alive\n", play->id,
		play->name);
		play->cycle_live = info->cycle_total;
	}
}
