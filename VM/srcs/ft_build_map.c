/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:40 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/24 19:20:36 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int			ft_add_player_to_map(int index, t_info *info, int id,
		unsigned char *map)
{
	t_player	*play;
	int			index_play;

	index_play = 0;
	play = ft_player_by_id(info->play, id);
	ft_addchariot(&info->chariot, ft_new_chariot(play->id, index, info));
	while (index_play < play->code_size)
	{
		map[index + index_play] = play->code[index_play];
		index_play++;
	}
	return (play->code_size);
}

int			ft_build_map(t_info *info)
{
	int				index;
	int				insert;

	insert = info->nb_players - 1;
	index = MEM_SIZE;
	while (index >= 0)
	{
		if (index == (insert * (MEM_SIZE / info->nb_players)))
		{
			ft_add_player_to_map(index, info, insert + 1, info->map);
			insert = (insert > 0 ? insert - 1 : insert);
		}
		else
			info->map[index] = 0;
		index--;
	}
	ft_parcour_map(info, info->chariot);
	return (1);
}
