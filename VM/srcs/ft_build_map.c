/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 14:06:07 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:43:08 by qbarrier    ###    #+. /#+    ###.fr     */
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
	ft_addchariot(&info->chariot, ft_new_chariot(play->id, index, info));
	while (index_play < play->code_size)
	{
		map[index + index_play] = play->code[index_play];
//		printf("C[%d]I[%d]\n", map[index + index_play], play->code[index_play]);
		index_play++;
	}
	return (play->code_size);

}

int			ft_build_map(t_info *info)
{
	unsigned char	*map;
	int				index;
	int				insert;

	insert = info->nb_players - 1;
	index = MEM_SIZE;
	if (!(map = (malloc(sizeof(char) * MEM_SIZE + 1))))
		return (0);
	while (index >= 0)
	{
		if (index == (insert * (MEM_SIZE / info->nb_players)))
		{
			printf("PLAYER [%d] AT index [%d]\n", insert + 1, index);
			ft_add_player_to_map(index, info, insert + 1, map);
			insert = (insert > 0 ? insert - 1 : insert);
		}
		else
			map[index] = 0;
		index--;
	}
	info->map = map;
//	ft_display_map(info);
	ft_display_chariot(info);
	return (1);
}
