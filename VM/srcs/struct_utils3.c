/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 19:13:13 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 17:52:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**	PERMET DE LIRE 4 OCTET A pc->OP pos + ARG
*/

//		VERIFIER SI ON STOCK LES IND EN UNSIGNED OU PAS
int			ft_indirect_arg(t_info *info, t_chariot *pc, int arg)
{
	int	res;
	int size;
	int	index;
	int	idx;

	if (pc->op < 13)
		idx = IDX_MOD;
	else
		idx = 1;
	size = REG_SIZE;
	index = (pc->pos - 2 + (arg % idx)) % MEM_SIZE;
	res = 0;
	while (size > 0)
	{
		res += info->map[index] * ft_pow(16, ((size * 2) - 2));
		index = (index + 1) % MEM_SIZE;
		size--;
	}
	return (res);
}
