/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:06:33 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:53:42 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

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
	if (!(info = malloc(sizeof(t_info))))
		return (NULL);
	info->line = NULL;
	info->intline = NULL;
	info->play = NULL;
	return (info);
}
