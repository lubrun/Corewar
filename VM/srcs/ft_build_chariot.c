/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_chariot.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 13:59:55 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:20:51 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_build_chariot(t_info *info, int index, t_player *play)
{
	ft_new_chariot(play->id, index, info);
	return (1);
}
