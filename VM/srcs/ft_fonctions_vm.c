/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 16:27:01 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:52:38 by qbarrier    ###    #+. /#+    ###.fr     */
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
	if (pc->type_arg[0] == 3)
		pc->arg[0] = ft_read_at(info, (pc->pos + pc->arg[0] - 2) % MEM_SIZE);
	////// Pas sur mais si arg[1] est indirect c'est l'inverse pour le carry ?
	if (pc->arg[0] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->r[pc->arg[1] - 1] = pc->arg[0];
	printf("PLAYER [%d]LD r[%d] = [%d]\n",pc->player, pc->arg[1], pc->arg[0]);
}

/*
**	augmente le compteur de LIVE dans le pc et le compteur total
**	Si arg[0] correspond a un joueur mais en negatif (-1) le joueur 1
**	sera en vie a cet instantOP 1
*/
// Est-ce qu'un joueur peut ressucite s'il na pas ete live depuis + d'un Cycle to die ?
void		ft_live(t_info *info, t_chariot *pc)
{
	t_player *play;

	pc->cycle_live++;
	info->live_total++;
	printf("\t LIVE cycle [%d] CHARIOT [%d] live -> [%d] arg[0][%d]\n", info->cycle_total, pc->player, pc->cycle_live, pc->arg[0]);
	if ((play = ft_player_by_id(info->play, (pc->arg[0] * - 1))))
	{
		play->cycle_live = info->cycle_total;
		printf("\t LIVE cycle [%d] PLAYER [%d] live -> [%d]\n", info->cycle_total, play->id, play->cycle_live);
//		printf("PLAYER [%d] live -> [%d]\n", play->id, play->cycle_live);
	}
}
