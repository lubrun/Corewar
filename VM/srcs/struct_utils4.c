/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 15:32:33 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:25:57 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_free_chariot(t_chariot *pc)
{
	printf("BITE10\n");
	pc->next = NULL;
	pc->start = NULL;
	free(pc->r);
	free(pc);
	printf("BITE11\n");
}

void		ft_del_chariot(t_info *info, int id_player)
{
	t_chariot *pc;
	t_chariot *tmp;

	printf("DEL CHARIOT ID [%d]\n", id_player);
	ft_display_chariot(info);
	printf("BITE1\n");
	pc = info->chariot;
	while (pc && pc->player == id_player)
	{
	printf("BITE2\n");
		info->chariot = pc->next;
		ft_free_chariot(pc);
		pc = info->chariot;
	}
	while (pc->next)
	{
	printf("BITE3\n");
		if (pc->next->player == id_player)
		{
			printf("BITE4\n");
			tmp = pc->next->next;
			ft_free_chariot(pc->next);
			if ((pc->next = tmp) != NULL)
				break;
		}
		pc = pc->next;
	}
}
