/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:31 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:25:26 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int			ft_winner(t_info *info, t_player *play)
{
	int			res;
	t_player	*winner;

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
	return (0);
}

void		ft_swap_player(t_player *play1, t_player *play2)
{
	int				swap_int;
	unsigned char	*swap_code;
	char			*swap_char;

	swap_int = play1->id;
	play1->id = play2->id;
	play2->id = swap_int;
	swap_code = play1->code;
	play1->code = play2->code;
	play2->code = swap_code;
	swap_char = play1->name;
	play1->name = play2->name;
	play2->name = swap_char;
	swap_char = play1->comment;
	play1->comment = play2->comment;
	play2->comment = swap_char;
	swap_int = play1->code_size;
	play1->code_size = play2->code_size;
	play2->code_size = swap_int;
	swap_int = play1->mapped;
	play1->mapped = play2->mapped;
	play2->mapped = swap_int;
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

void		ft_del_chariot(t_info *info, t_chariot *pc)
{
	t_chariot *start;
	t_chariot *tmp;

	start = info->chariot;
	if (start && pc && start == pc)
		ft_del_chariot_first(info, pc);
	else if (pc)
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
					break ;
			}
			start = start->next;
		}
	}
}
