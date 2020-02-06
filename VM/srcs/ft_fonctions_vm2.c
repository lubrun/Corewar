/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 19:14:08 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:01:41 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	Ecrit dans le r[arg2] la valeur a l'adresse r[arg0] + r[arg1] OP 10
*/

void		ft_ldi(t_info *info, t_chariot *pc)
{
	int verbose;
	int res;
	int moove;

	verbose = info->verbose;
	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	moove = (pc->arg[0] + pc->arg[1]) % IDX_MOD;
	moove = (pc->pos - 2 + moove) % MEM_SIZE;
	res = ft_read_at(info, moove);
	pc->r[pc->arg[2] - 1] = res;
}

/*
** Zjump renvoi le pc->pos a une position, OP 9
*/

//	?? doit reverse les bits tout le temps ?
void	ft_zjmp(t_info *info, t_chariot *pc)
{
	int	max;
	int	res;

	max = ft_pow(16, DIR_SIZE);
	printf("JUMP arg[%d]max[%d]map[%d]carry[%d]\n", pc->arg[0], max, info->map[pc->pos], pc->carry);
	res = (pc->arg[0] - max) % IDX_MOD;
	if (pc->carry == 1)
	{
		pc->jump = 0;
		pc->pos = (pc->pos - 1 + res) % MEM_SIZE;
		printf("ARG 1 JUMP [%d][%d]\n", res, info->map[pc->pos]);
	}
}

/*
**	Comparation en bits "^" op 8
*/

void	ft_xor(t_info *info, t_chariot *pc)
{
	int	norme;

	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	norme = info->verbose;
	if ((pc->r[pc->arg[2]] = pc->arg[0] ^ pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Comparation en bits "|" op 7
*/

void	ft_or(t_info *info, t_chariot *pc)
{
	int	norme;

	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	norme = info->verbose;
	if ((pc->r[pc->arg[2]] = pc->arg[0] | pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

/*
**	Comparation en bits "&" op 6
*/

void	ft_and(t_info *info, t_chariot *pc)
{
	int	norme;

	if (pc->type_arg[0] == 1)
		pc->arg[0] = pc->r[pc->arg[0] - 1];
	if (pc->type_arg[1] == 1)
		pc->arg[1] = pc->r[pc->arg[1] - 1];
	norme = info->verbose;
	if ((pc->r[pc->arg[2]] = pc->arg[0] & pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	printf("\tAND cycle [%d]R == [%d] carry [%d]\n", info->cycle_total, pc->r[pc->arg[2]], pc->carry);
}
