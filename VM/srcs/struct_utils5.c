/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils5.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 15:14:12 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:44:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_new_jump(int tab[4], t_chariot *pc)
{
	int index;

	index = -1;
	while (++index < 3)
		printf("BUG TAB[%d]=[%d]\n", index, pc->tab_jump[index]);
	if (pc->op == 9 || pc->op == 10 || pc->op == 12 || pc->op == 14
			|| pc->op == 15)
		return (ft_size_to_read(tab, 2, pc));
	else
		return(ft_size_to_read(tab, 4, pc));
}
