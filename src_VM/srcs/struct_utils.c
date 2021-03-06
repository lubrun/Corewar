/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:18 by qbarrier          #+#    #+#             */
/*   Updated: 2020/03/03 20:15:02 by lubrun           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

t_player		*ft_player_by_id(t_player *play, int id)
{
	while (play && play->id != id)
		play = play->next;
	if (!play)
		return (NULL);
	else
		return (play);
}

t_chariot		*ft_new_chariot(int player, int pos, t_info *info)
{
	t_chariot	*new;
	int			index;
	static int	pross;

	if (pross > 150000)
		ft_exit_free_error("Too Many Pross For Computer", info);
	index = 0;
	if (!(new = malloc(sizeof(t_chariot))))
		return (NULL);
	if (!(new->r = malloc(sizeof(int) * (REG_NUMBER + 1))))
		return (NULL);
	if (++pross > info->nb_players)
		new->pross = pross;
	else
		new->pross = player;
	new->next = NULL;
	new->pos = pos;
	new->cycle_live = 0;
	new->last_live = 0;
	new->carry = 0;
	new->jump = 0;
	new->r[index++] = player * -1;
	while (index++ < REG_NUMBER)
		new->r[index] = 0;
	return (ft_new_chariot2(new, player));
}

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
	if (!(player = ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->name = NULL;
	player->comment = NULL;
	player->next = NULL;
	player->cycle_live = 0;
	player->code_size = 0;
	player->mapped = 0;
	return (player);
}

t_info			*ft_new_info(t_info *info)
{
	int index;

	index = 0;
	if (!(info = ft_memalloc(sizeof(t_info))))
		return (NULL);
	if (!(info->preset_player = ft_memalloc(sizeof(int) * (MAX_PLAYERS + 1))))
		return (NULL);
	if (!(info->map = ft_memalloc(sizeof(unsigned char) * (MEM_SIZE + 1))))
		return (NULL);
	while (index < MAX_PLAYERS)
		info->preset_player[index++] = 0;
	info->cycle_total = 0;
	info->verbose = 0;
	info->dump_cycle = -1;
	info->dump_size = 0;
	info->live_total = 0;
	info->cycle_to_die = CYCLE_TO_DIE;
	info->max_check = 0;
	info->delta = 0;
	info->chariot = NULL;
	info->line = NULL;
	info->intline = NULL;
	info->play = NULL;
	ft_add_fonction_to_info(info);
	return (info);
}
