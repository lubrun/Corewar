/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:37 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 20:28:49 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_del_chariot_first(t_info *info, t_chariot *pc)
{
	t_chariot	*tmp;
	t_chariot	*start;

	start = info->chariot;
	if (start->next)
		tmp = start->next;
	else
		tmp = NULL;
	ft_free_chariot(pc);
	info->chariot = tmp;
}

int			ft_new_jump(int tab[4], t_chariot *pc)
{
	int	index;

	index = -1;
	if (pc->op == 11 || pc->op == 9 || pc->op == 10 || pc->op == 12 ||
			pc->op == 14 || pc->op == 15)
		return (ft_size_to_read(tab, 2, pc));
	else
		return (ft_size_to_read(tab, 4, pc));
}
