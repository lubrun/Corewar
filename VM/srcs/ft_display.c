/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:08 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/17 14:42:17 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void	ft_display_chariot(t_info *info)
{
	t_chariot *pc;

	pc = info->chariot;
	while (pc)
	{
		printf("CHAR ID[%d] POS [%d]\t STARTID[%d]\n",
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
				printf("%c", (tmp + 87));
			else
				printf("%c", (tmp + 48));
		}
		else
			printf("0");
		if (c >= 10)
			printf("%c", (c + 87));
		else
			printf("%c", (c + 48));
		index++;
	}
}

void	ft_print_map(t_info *info, unsigned char *str, int size)
{
	int				index;
	unsigned char	c;
	unsigned char	tmp;

	index = -1;
	while (++index < size)
	{
		c = str[index];
		if (c >= 16)
		{
			tmp = c / 16;
			c = c % 16;
			if (tmp >= 10)
				printf("%c", (tmp + 87));
			else
				printf("%c", (tmp + 48));
		}
		else
			printf("0");
		if (c >= 10)
			printf("%c ", (c + 87));
		else
			printf("%c ", (c + 48));
		if ((index + 1) % info->dump_size == 0 && index > 0)
			printf("\n");
	}
}

void	ft_display_map(t_info *info)
{
	ft_print_map(info, info->map, MEM_SIZE);
}

void	ft_display_play(t_player *play)
{
	int				index;

	index = 0;
	if (play->id == 1)
		printf("Introducing contestants...\n");
	if (play->next)
		ft_display_play(play->next);
	printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", play->id, play->code_size, play->name, play->comment);
}
