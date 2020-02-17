/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:27:01 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/09 18:10:36 by lelajour         ###   ########.fr       */
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
	printf("SUB arg1 2 3 [%d][%d]r[%d] carry = [%d]\n", pc->arg[0], pc->arg[1], pc->r[pc->arg[2] - 1], pc->carry);
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
	printf("ADD arg1 2 3 [%d][%d]r[%d] carry = [%d]\n", pc->arg[0], pc->arg[1], pc->r[pc->arg[2] - 1], pc->carry);
}

/*
**	Ecrit r[arg[0] - 1] dans r[arg[1] - 1]
**	ou a la postition pos + (arg[1] % IDX) -2 OP 3
*/

void		ft_st(t_info *info, t_chariot *pc)
{
	int moove;

	printf("ST rg01[%d][%d]\n", pc->arg[0], pc->arg[1]);
	pc->arg[0] = pc->r[pc->arg[0] - 1];
	printf("ST r[arg0] = [%d]\n", pc->arg[0]);
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

///// !!! pour LD et LLD LA VM lit que 2 octet en INDIRECT, c'est je pense une erreure venant de leur op.h ou T_DIR = 2 et T_IND = 4 ce qui est cense etre l'inverse
//
void		ft_ld(t_info *info, t_chariot *pc)
{
	int verbose;

	verbose = info->verbose;
	if (pc->type_arg[0] == 3)
		pc->arg[0] = ft_read_at(info, (pc->pos - 2 + (pc->arg[0] % IDX_MOD)) % MEM_SIZE);
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
	if (check_bit(info->verbose, 0) == 0)
		printf("\t LIVE cycle [%d] CHARIOT [%d] live -> [%d] arg[0][%d]\n", info->cycle_total, pc->player, pc->cycle_live, pc->arg[0]);
	if ((play = ft_player_by_id(info->play, (pc->arg[0] * - 1))))
	{
		play->cycle_live = info->cycle_total;
		if (check_bit(info->verbose, 0) != 0)
			printf("Player %d (%s) is said to be alive\n", play->id, play->name);
		else
			printf("\t LIVE cycle [%d] PLAYER [%d] live -> [%d]\n", info->cycle_total, play->id, play->cycle_live);
//		printf("PLAYER [%d] live -> [%d]\n", play->id, play->cycle_live);
	}
}
