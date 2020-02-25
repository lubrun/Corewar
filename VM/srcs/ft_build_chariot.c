/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_chariot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <qbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:17:33 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/24 23:39:21 by lelajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_build_chariot(t_info *info, int index, t_player *play)
{
	ft_new_chariot(play->id, index, info);
	return (1);
}
