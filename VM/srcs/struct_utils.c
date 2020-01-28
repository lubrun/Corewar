/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:06:33 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:43:01 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

	index = 0;
	if (!(new = malloc(sizeof(t_chariot))))
		return (NULL);
	if (!(new->r = malloc(sizeof(int) * (REG_NUMBER + 1))))
		return (NULL);
	new->next = NULL;
	new->player = player;
	new->pos = pos;
	new->carry = 0;
	new->op = 0;
	new->opc = 0;
	new->jump = 0;
	new->r[index++] = 1;
	while (index++ < REG_NUMBER)
		new->r[index] = 0;
	if (info->chariot)
		new->start = info->chariot;
	else
		new->start = new;
	return (new);
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
	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->name = NULL;
	player->comment = NULL;
	player->next = NULL;
	player->code_size = 0;
	player->mapped = 0;
	return (player);
}

t_info			*ft_new_info(t_info *info)
{
	int index;

	index = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (NULL);
	if (!(info->preset_player = malloc(sizeof(char) * (MEM_SIZE + 1))))
		return (NULL);
	if (!(info->map = malloc(sizeof(int) * (MAX_PLAYERS + 1))))
		return (NULL);
	while (index < MAX_PLAYERS)
		info->preset_player[index++] = 0;
	info->verbose = 0;
	info->dump_cycle = 0;
	info->dump_size = 0;
	info->chariot = NULL;
	info->line = NULL;
	info->intline = NULL;
	info->play = NULL;
	return (info);
}
