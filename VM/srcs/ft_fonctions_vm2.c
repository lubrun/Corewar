/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 19:14:08 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 17:03:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
** Zjump renvoi le pc->pos a une position, id 9
*/

//	?? doit reverse les bits tout le temps ?
void	ft_zjmp(t_info *info, t_chariot *pc)
{
	int	max;
	int	res;

	max = ft_pow(16 , DIR_SIZE);
	printf("JUMP arg[%d]map[%d]\t", pc->arg[0], info->map[pc->pos]);
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

	norme = info->verbose;
	if ((pc->r[pc->arg[2]] = pc->arg[0] & pc->arg[1]) == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}
