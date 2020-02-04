/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parcour_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 18:54:54 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 16:55:35 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
** TANT QUE CAST-- !=0
** SINON ON CHECK AVEC OPCODE LES ARGS
** PUIS ON EXECUTE LE CODE
*/

int		ft_tempo_cast(t_info *info, t_chariot *pc, int op)
{
	if (pc->cast > 0)
	{
		--pc->cast;
		return (pc->pos);
	}
	printf("PC->POS ENTER OP [%d][%d]\n", pc->op, pc->pos);
	////// EST-CE QU'ON CHECK SI L'OP A GECHAN ?
	if (op != 1 && op!= 9 && op != 12 && op != 15)
	{
		pc->opc = info->map[pc->pos];
		if (!ft_opcode(info->map[pc->pos], op, info, pc))
		{
			ft_new_chariot2(pc);
	//		pc->jump = 0;
			return (pc->pos + 1); // ou return jump ?
		}
		pc->pos = (pc->pos + 1) % MEM_SIZE;
	}
	else if (op == 1)
		pc->jump = 4;
	else
		pc->jump = 2;
	ft_read_arguments_opc(info, pc);

	printf("PC->POS OUT OP[%d][%d]+JUMP[%d]\n\n", pc->op, pc->pos, pc->pos + pc->jump);
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
		pc = info->chariot;
		while (pc)
		{
			if (pc->op)
				pc->pos = (ft_tempo_cast(info, pc, pc->op) % MEM_SIZE);
			else if (info->map[pc->pos] >= 0x01 && info->map[pc->pos] <= 0x10)
			{
				pc->cast = 100;//fonctions.
				pc->op = info->map[pc->pos];
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			}
			else
				pc->pos = (pc->pos + 1) % MEM_SIZE;
			ft_player_by_id(info->play, pc->player)->cycle_live++;
			// les 2 fonctions dessous sont soit la soit dans l'autre while.
			//fonction decremente cycle to die et le reset en soustrayant cycle delta
			//fonction check si en vie
			pc = pc->next;
		}
	}
//		AFFICHE LA MAP DE DUMP SIZE
	return (1);
}
