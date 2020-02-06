/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 16:27:01 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:35:52 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

	printf("ST arg01[%d][%d]", pc->arg[0], pc->arg[1]);
	pc->arg[0] = pc->r[pc->arg[0] - 1];
	printf("r[arg0] = [%d]\n", pc->r[pc->arg[0] - 1]);
	if (pc->type_arg[1] == 1)
	{
		pc->r[pc->arg[1] - 1] = pc->arg[0];
	}
	else
	{
		moove = (pc->arg[1]) % IDX_MOD;
		ft_write_on_map(info, pc->arg[0], (moove + pc->pos - 2) % MEM_SIZE, REG_SIZE);
	}
}

/*
**	Ecrit arg[1] dans le registre r[arg[0] - 1] OP 2
*/

void		ft_ld(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	////// Pas sur mais si arg[1] est indirect c'est l'inverse pour le carry ?
	if (pc->arg[0] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->r[pc->arg[1] - 1] = pc->arg[0];
}

/*
**	augmente le compteur de LIVE dans le joueur? OP 1
*/

void		ft_live(t_info *info, t_chariot *pc)
{
	t_player *play;
	
	if ((play = ft_player_by_id(info->play, (pc->arg[0] * - 1))))
	{
		printf("\t LIVE cycle [%d] PLAYER [%d] live -> [%d]\n", info->cycle_total, pc->player, pc->cycle_live);
		pc->cycle_live++;
		play->cycle_live = info->cycle_total;
		info->live_total++;
//		printf("PLAYER [%d] live -> [%d]\n", play->id, play->cycle_live);
	}
}
