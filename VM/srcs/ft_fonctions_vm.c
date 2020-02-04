/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions_vm.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 16:27:01 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 17:04:19 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/coreware.h"

void		ft_live(t_info *info, t_chariot *pc)
{
	t_player *play;

	printf("LIVE OP [%d]P[%d]\n", pc->op, pc->player);
	if ((play = ft_player_by_id(info->play, pc->arg[0])))
	{
		printf("PLAYER [%d] live -> [%d]\n", play->id, play->cycle_live);
		play->cycle_live = 0;
		printf("PLAYER [%d] live -> [%d]\n", play->id, play->cycle_live);
	}
}
