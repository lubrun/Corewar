/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:03:05 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/26 12:03:06 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void	ft_display_chariot(t_info *info)
{
	t_chariot *pc;

	pc = info->chariot;
	while (pc)
	{
		ft_printf("CHAR ID[%d] POS [%d]\t STARTID[%d]\n",
				pc->player, pc->pos, pc->start->pos);
		pc = pc->next;
	}
}

void	ft_print_octet(unsigned char *str, int size)
{
	int				index;
	unsigned char	c;
	unsigned char	tmp;

	index = 0;
	while (index < size)
	{
		c = str[index];
		if (c >= 16)
		{
			tmp = c / 16;
			c = c % 16;
			if (tmp >= 10)
				ft_printf("%c", (tmp + 87));
			else
				ft_printf("%c", (tmp + 48));
		}
		else
			ft_printf("0");
		if (c >= 10)
			ft_printf("%c", (c + 87));
		else
			ft_printf("%c", (c + 48));
		index++;
	}
}

void	ft_print_map(t_info *info, unsigned char *str, int size, int index)
{
	unsigned char	c;
	unsigned char	tmp;

	while (++index < size)
	{
		c = str[index];
		if (c >= 16)
		{
			tmp = c / 16;
			c = c % 16;
			if (tmp >= 10)
				ft_printf("%c", (tmp + 87));
			else
				ft_printf("%c", (tmp + 48));
		}
		else
			ft_printf("0");
		if (c >= 10)
			ft_printf("%c ", (c + 87));
		else
			ft_printf("%c ", (c + 48));
		if ((index + 1) % info->dump_size == 0 && index > 0)
			ft_printf("\n");
	}
}

void	ft_display_map(t_info *info)
{
	ft_print_map(info, info->map, MEM_SIZE, -1);
}

void	ft_display_play(t_player *play)
{
	int				index;

	index = 0;
	if (play->id == 1)
		ft_printf("Introducing contestants...\n");
	if (play->next)
		ft_display_play(play->next);
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			play->id, play->code_size, play->name, play->comment);
}
