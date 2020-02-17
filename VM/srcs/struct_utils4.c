/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:31 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/17 14:32:59 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_winner(t_info *info, t_player *play)
{
	int res;
	t_player *winner;

	res = 0;
	winner = play;
	while (play)
	{
		if (res < play->cycle_live)
		{
			res = play->cycle_live;
			winner = play;
		}
		play = play->next;
	}
	printf("Contestant %d, \"%s\", has won !\n", winner->id, winner->name);
	res = info->verbose;
}

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
	swap_id = play1->mapped;
	play1->mapped = play2->mapped;
	play2->mapped = swap_id;
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

void		ft_del_chariot(t_info *info, t_chariot *pc)
{
	t_chariot *start;
	t_chariot *tmp;

///	printf("DEL CHARIOT ID [%d]\n", pc->player);
//	ft_display_chariot(info);
	start = info->chariot;
	if (start == pc)
	{
		tmp = start->next;
		ft_free_chariot(pc);
		info->chariot = tmp;
	}
	else
	{
		while (start->next)
		{
			if (start->next == pc)
			{
				if (start->next->next)
					tmp = start->next->next;
				else
					tmp = NULL;
				ft_free_chariot(pc);
				if ((start->next = tmp) == NULL)
					break;
			}
			start = start->next;
		}
//		ft_display_chariot(info);
	}
}
