/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 17:39:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 19:12:55 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	ECRIT LA VALEUR CONTENUE DANS r[ARG[0]] Sur REG_SIZE octet DANS
**	(arg1 +arg2) % IDX_MOD DEPUIS L'OP (d'ou le -2 pour moove)
*/

void		ft_sti(t_info *info, t_chariot *pc)
{
	int	moove;
	int	val;
	int	index;

	index = 0;
	val = pc->arg[0];
	moove = (pc->arg[1] + pc->arg[2] - 2) % IDX_MOD;
//	while (index < 4)
//		printf("\t---MOOVE [%d] octet map = [%x]\n", moove, info->map[(pc->pos + moove + index++) % MEM_SIZE]);
	ft_write_on_map(info, val, moove + pc->pos, REG_SIZE);
	index = 0;
//	while (index < 4)
//		printf("\t---2MOOVE [%d] octet map = [%x]\n", moove, info->map[(pc->pos + moove + index++) % MEM_SIZE]);

}
