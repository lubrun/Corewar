/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:27 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 16:44:22 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_add_first_chariot(t_chariot **alst, t_chariot *new_chariot)
{
	t_chariot *tmp;

	if (*alst == NULL)
		*alst = new_chariot;
	else
	{
		tmp = *alst;
		new_chariot->next = tmp;
		*alst = new_chariot;
	}
}

void		ft_add_cast(t_info *info)
{
	info->tab_cast[0] = 10;
	info->tab_cast[1] = 5;
	info->tab_cast[2] = 5;
	info->tab_cast[3] = 10;
	info->tab_cast[4] = 10;
	info->tab_cast[5] = 6;
	info->tab_cast[6] = 6;
	info->tab_cast[7] = 6;
	info->tab_cast[8] = 20;
	info->tab_cast[9] = 25;
	info->tab_cast[10] = 25;
	info->tab_cast[11] = 800;
	info->tab_cast[12] = 10;
	info->tab_cast[13] = 50;
	info->tab_cast[14] = 1000;
	info->tab_cast[15] = 2;
}

t_chariot	*ft_pc_cpy(t_chariot *dest, t_chariot *source)
{
	int index;

	index = 0;
	dest->carry = source->carry;
	dest->cycle_live = source->cycle_live;
	while (index < REG_NUMBER)
	{
		dest->r[index] = source->r[index];
		index++;
	}
	return (dest);
}

/*
** Lit et renvoie 4 octet lu depuis map[index].
*/

int			ft_read_at(t_info *info, int index)
{
	int	res;
	int size;

	if (index < 0)
		index += MEM_SIZE;
	size = REG_SIZE;
	res = 0;
	while (size > 0)
	{
		res += info->map[index] * ft_pow(16, ((size * 2) - 2));
		index = (index + 1) % MEM_SIZE;
		size--;
	}
	return (res);
}

/*
**	PERMET DE LIRE 4 OCTET A pc->OP pos + ARG
*/

int			ft_indirect_arg(t_info *info, t_chariot *pc, int arg)
{
	int	res;
	int size;
	int	index;
	int	idx;

	if (pc->op == 3 || pc->op == 11)
		return (arg);
	if (pc->op != 13)
		idx = IDX_MOD;
	else
		idx = 1;
	size = REG_SIZE;
	index = (pc->pos - 2 + (arg % idx)) % MEM_SIZE;
	res = 0;
	while (size > 0)
	{
		res += info->map[index] * ft_pow(16, ((size * 2) - 2));
		index = (index + 1) % MEM_SIZE;
		size--;
	}
	return (res);
}
