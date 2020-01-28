/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 14:06:07 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:12:22 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int			ft_add_player_to_map(int index, t_info *info, int id, unsigned char *map)
{
	t_player	*play;
	int			index_play;

	index_play = 0;
	play = ft_player_by_id(info->play, id);
	while (index_play < play->code_size)
	{
		map[index + index_play] = play->code[index_play];
		printf("C[%d]I[%d]\n", map[index + index_play], play->code[index_play]);
		index_play++;
	}
	return (play->code_size);

}

int			ft_build_map(t_info *info)
{
	unsigned char	*map;
	int				index;
	int				insert;

	insert = 0;
	index = 0;
	if (!(map = (malloc(sizeof(char) * MEM_SIZE + 1))))
		return (0);
	while (index < MEM_SIZE)
	{
		if (index == (insert * (MEM_SIZE / info->nb_players)))
		{
			printf("PLAYER [%d] AT index [%d]\n", insert + 1, index);
			index += ft_add_player_to_map(index, info,
					info->nb_players - insert, map);
			insert = (insert < (info->nb_players - 1) ? insert + 1 : insert);
		}
		else
			map[index++] = 0;
	}
	info->map = map;
//	ft_display_map(info);
	return (1);
}
