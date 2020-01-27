/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:06:33 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 13:25:32 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

void			ft_addplayer(t_player **alst, t_player *new_player)
{
	t_player *tmp;

	if (*alst == NULL)
		*alst = new_player;
	else
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_player;
	}
}

t_player		*ft_new_player(t_player *player)
{
	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->name = NULL;
	player->comment = NULL;
	player->next = NULL;
	player->code_size = 0;
	return (player);
}

t_info			*ft_new_info(t_info *info)
{
	int index;

	index = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (NULL);
	if (!(info->preset_player = malloc(sizeof(int) * (MAX_PLAYERS + 1))))
		return (NULL);
	while (index < MAX_PLAYERS)
		info->preset_player[index++] = 0;
	info->verbose = 0;
	info->dump_cycle = 0;
	info->dump_size = 0;
	info->line = NULL;
	info->intline = NULL;
	info->play = NULL;
	return (info);
}
