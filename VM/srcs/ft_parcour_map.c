/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcour_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:33:06 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/25 15:35:08 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_check_alive(t_info *info, t_chariot *pc)
{
	if (pc->next)
		if (ft_check_alive(info, pc->next) == 0)
			return (0);
	if (pc->cycle_live == 0 || info->cycle_to_die < 0)
		ft_del_chariot(info, pc);
	else
		pc->cycle_live = 0;
	if (info->chariot == NULL)
		return (0);
	return (1);
}

int		ft_check_cycle_to_die(t_info *info)
{
	if (--info->cycle_to_die > 0)
		return (1);
	if (ft_check_alive(info, info->chariot) == 0)
		return (0);
	if (info->live_total >= NBR_LIVE || info->max_check >= (MAX_CHECKS - 1))
	{
		info->delta += CYCLE_DELTA;
		info->cycle_to_die = CYCLE_TO_DIE - info->delta;
		info->max_check = 0;
	}
	else
	{
		info->cycle_to_die = CYCLE_TO_DIE - info->delta;
		info->max_check++;
	}
	if (check_bit(info->verbose, 1) != 0)
		ft_printf("Cycle to die is now %d\n", info->cycle_to_die);
	info->ctd = info->cycle_to_die;
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
	if (op != 1 && op != 9 && op != 12 && op != 15)
	{
		pc->opc = info->map[pc->pos];
		if (!ft_opcode(info->map[pc->pos], op, info, pc))
		{
			ft_new_chariot2(pc);
			return (pc->pos + pc->jump + 1);
		}
		pc->pos = (pc->pos + 1) % MEM_SIZE;
	}
	else if (op == 1)
		pc->jump = 4;
	else
		pc->jump = 2;
	ft_read_arguments_opc(info, pc);
	ft_new_chariot2(pc);
	return (pc->pos + pc->jump);
}

/*
** Faire avancer les chariots chacun son tour
** Conditions d'arret : dump arrive a terme || tous les CHARIOTS sont morts.
*/

int		ft_parcour_map(t_info *info, t_chariot *pc)
{
	while (info->dump_cycle-- != 0)
	{
		info->cycle_total++;
		pc = info->chariot;
		if (check_bit(info->verbose, 1) != 0)
			ft_printf("It is now cycle %d\n", info->cycle_total);
		while (pc)
		{
			if (pc->op)
				pc->pos = (ft_tempo_cast(info, pc, pc->op) % MEM_SIZE);
			else if (info->map[pc->pos] >= 0x01 && info->map[pc->pos] <= 0x10)
			{
				pc->op = info->map[pc->pos];
				pc->cast = info->tab_cast[pc->op - 1] - 1;
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			}
			else
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			pc = pc->next;
		}
		if (ft_check_cycle_to_die(info) == 0)
			return (ft_winner(info, info->play));
	}
	ft_display_map(info);
	return (1);
}
