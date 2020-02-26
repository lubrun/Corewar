/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_chariot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:00:22 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/26 12:00:23 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

int		ft_build_chariot(t_info *info, int index, t_player *play)
{
	ft_new_chariot(play->id, index, info);
	return (1);
}
