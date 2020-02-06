/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 15:32:33 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:46:04 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_swap_player(t_player *play1, t_player *play2)
{
	int				swap_id;
	unsigned char	*swap_code;
	char			*swap_name;
	char			*swap_comment;
	int				swap_code_size;

	swap_id = play1->id;
	swap_code = play1->code;
	swap_name = play1->name;
	swap_comment = play1->comment;
	swap_code_size = play1->code_size;
	play1->id = play2->id;
	play1->code = play2->code;
	play1->name = play2->name;
	play1->comment = play2->comment;
	play1->code_size = play2->code_size;
	play2->id = swap_id;
	play2->code = swap_code;
	play2->name = swap_name;
	play2->comment = swap_comment;
	play2->code_size = swap_code_size;
}

void		ft_tri_player(t_info *info)
{
	t_player *play1;
	t_player *play2;

	play1 = info->play;
	play2 = info->play;
	while (play1)
	{
		play2 = info->play;
		while (play2)
		{
			if (play1->id > play2->id)
				ft_swap_player(play1, play2);
			play2 = play2->next;
		}
		play1 = play1->next;
	}
}

void		ft_free_chariot(t_chariot *pc)
{
	pc->next = NULL;
	pc->start = NULL;
	free(pc->r);
	free(pc);
}

void		ft_del_chariot(t_info *info, int id_player)
{
	t_chariot *pc;
	t_chariot *tmp;

	printf("DEL CHARIOT ID [%d]\n", id_player);
	ft_display_chariot(info);
	pc = info->chariot;
	while (pc && pc->player == id_player)
	{
		info->chariot = pc->next;
		ft_free_chariot(pc);
		pc = info->chariot;
		pc->start = info->chariot;
	}
	while (pc->next)
	{
		if (pc->next->player == id_player)
		{
			pc->next->start = info->chariot;
			if (pc->next->next)
				tmp = pc->next->next;
			else
				tmp = NULL;
			ft_free_chariot(pc->next);
			if ((pc->next = tmp) == NULL)
				break;
		}
		pc = pc->next;
	}
	ft_display_chariot(info);
}
