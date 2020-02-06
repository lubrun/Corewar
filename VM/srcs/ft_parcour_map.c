/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parcour_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 18:54:54 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:46:12 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_check_alive(t_info *info, t_player *play)
{
	printf("\nCHECK ALIVE player [%d]live[%d] total cycle[%d]\n", play->id, play->cycle_live, info->cycle_total);
//	ft_display_play(play);
	if (play->cycle_live == 0)
	{
		info->nb_players -= 1;
		ft_del_chariot(info, play->id);
	}
	else
		play->cycle_live = 0;
	if (info->nb_players == 1)
		return (0);
	if (play->next)
		if (ft_check_alive(info, play->next) == 0)
			return (0);
	return (1);
}

int		ft_check_cycle_to_die(t_info *info)
{
//	printf("CHECK CYCLE TO DIE[%d]\n", info->cycle_to_die);
	if (--info->cycle_to_die > 0)
		return (1);
	if (ft_check_alive(info, info->play) == 0)
		return (0);
	if (info->live_total >= NBR_LIVE || info->max_check >= (MAX_CHECKS - 1))
	{
//		printf("1CTD live_total[%d]\n", info->live_total);
		info->delta += CYCLE_DELTA;
		info->cycle_to_die = CYCLE_TO_DIE - info->delta;
		info->max_check = 0;
	}
	else
	{
//		printf("2CTD max_check[%d] live[%d]\n", info->max_check, info->live_total);
		info->cycle_to_die = CYCLE_TO_DIE - info->delta;
		info->max_check++;
	}
	printf("cycle [%d] cycle to die is now %d\n", info->cycle_total, info->cycle_to_die);
	info->live_total = 0;
	return (1);
}

/*
** TANT QUE CAST-- !=0
** SINON ON CHECK AVEC OPCODE LES ARGS
** PUIS ON EXECUTE LE CODE
*/

int		ft_tempo_cast(t_info *info, t_chariot *pc, int op)
{
	if (--pc->cast > 0)
		return (pc->pos);
	printf("PC[%d]->POS ENTER OP [%d][%d]\n", pc->player,  pc->op, pc->pos);
	////// EST-CE QU'ON CHECK SI L'OP A GECHAN ?
	if (op != 1 && op != 9 && op != 12 && op != 15)
	{
		pc->opc = info->map[pc->pos];
		if (!ft_opcode(info->map[pc->pos], op, info, pc))
		{
			ft_new_chariot2(pc);
			//pc->jump = 0;
			return (pc->pos + 1); // ou return jump ?
		}
		pc->pos = (pc->pos + 1) % MEM_SIZE;
	}
	else if (op == 1)
		pc->jump = 4;
	else
		pc->jump = 2;
	ft_read_arguments_opc(info, pc);
	printf("PC[%d]->POS OUT OP[%d][%d]+JUMP[%d]\n\n", pc->player,
			pc->op, pc->pos, pc->pos + pc->jump);
	ft_new_chariot2(pc);
	return (pc->pos + pc->jump);
}

/*
** Faire avancer les chariots chacuns son tour
**
**
**
** Conditions d'arret : dump arrive a terme, plus qu'un joueur vivant.
*/

int		ft_parcour_map(t_info *info, t_chariot *pc)
{
	while (info->dump_cycle-- != 0) // si on a pas de dump il vaut -1 !int min ?
	{
		info->cycle_total++;
		printf("It is now cycle %d\n", info->cycle_total);
		pc = info->chariot;
		while (pc)
		{
			if (pc->op)
				pc->pos = (ft_tempo_cast(info, pc, pc->op) % MEM_SIZE);
			else if (info->map[pc->pos] >= 0x01 && info->map[pc->pos] <= 0x10)
			{
				pc->op = info->map[pc->pos];
				pc->cast = info->tab_cast[pc->op - 1] - 1;
				printf("CAST == [%d] OP[%d]\n", pc->cast, pc->op);
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			}
			else
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			pc = pc->next;
		}
		if (ft_check_cycle_to_die(info) == 0)
		{
			printf("\t\t END CYCLES\n");
			return (0);
		}
		//fonction decremente cycle to die et le reset en soustrayant cycle delta
			//fonction check si en vie
	}
//	ft_display_map(info);
	return (1);
}
