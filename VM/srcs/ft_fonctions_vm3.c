/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm3.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 17:39:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 17:01:07 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
** Creait un nouveau PC copie de l'actuel a la position pos + (arg[0]) OP 15
*/

void		ft_lfork(t_info *info, t_chariot *pc)
{
	int			moove;
	t_chariot	*new;
	////////////// - 2 ou - 1 ?
	moove = (pc->pos - 1 + (pc->arg[0]) % MEM_SIZE);
	new = ft_new_chariot(pc->player, pc->pos, info);
	ft_pc_cpy(new, pc);
	ft_addchariot(&info->chariot, new);
}
/*
**	Ecrit dans le r[arg2] la valeur a l'adresse r[arg0] + r[arg1] OP 14
*/

void		ft_lldi(t_info *info, t_chariot *pc)
{
	int verbose;
	int res;
	int moove;

	verbose = info->verbose;
	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	moove = (pc->arg[0] + pc->arg[1]);
	moove = (pc->pos - 2 + moove) % MEM_SIZE;
	res = ft_read_at(info, moove);
	pc->r[pc->arg[2] - 1] = res;
}
/*
**	Ecrit arg[1] dans le registre r[arg[0] - 1] mais sans idx (cf ft_indirect_arg) OP 13
*/

//corewarMalheureusement, la machine virtuelle d'origine ne fonctionne pas correctement. Et il lit 2 octets, pas 4. Peut-être qu'un bogue similaire est expliqué par les mêmes lignes que les problèmes dans les fichiers fournis

void		ft_lld(t_info *info, t_chariot *pc)
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
** Creait un nouveau PC copie de l'actuel a la position pos + (arg[0] % IDX) OP 12
*/

void		ft_fork(t_info *info, t_chariot *pc)
{
	int			moove;
	t_chariot	*new;
	////////////// - 2 ou - 1 ?
	moove = (pc->pos - 1 + (pc->arg[0] % IDX_MOD) % MEM_SIZE);
	new = ft_new_chariot(pc->player, pc->pos, info);
	ft_pc_cpy(new, pc);
	ft_addchariot(&info->chariot, new);
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

	index = 0;
	while (index < 3)
	{
		if (pc->type_arg[index] == 1)
			pc->arg[index] = pc->r[pc->arg[index] - 1];
		index++;
	}
	val = pc->arg[0];
	moove = (pc->arg[1] + pc->arg[2]) % IDX_MOD;
//	while (index < 4)
//		printf("\t---MOOVE [%d] octet map = [%x]\n", moove, info->map[(pc->pos + moove + index++) % MEM_SIZE]);
	ft_write_on_map(info, val, (moove + pc->pos - 2) % MEM_SIZE, REG_SIZE);
//	while (index < 4)
//		printf("\t---2MOOVE [%d] octet map = [%x]\n", moove, info->map[(pc->pos + moove + index++) % MEM_SIZE]);

}
