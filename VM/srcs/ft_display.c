/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 09:38:21 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 14:12:09 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

void	ft_print_map(unsigned char *str, int size)
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
			printf("%c ", (c + 87));
		else
			printf("%c ", (c + 48));
		if ((index + 1) % 64 == 0 && index > 0)
			printf("\n");
		index++;
	}
}

void	ft_display_map(t_info *info)
{
	ft_print_map(info->map, MEM_SIZE);
}

void	ft_display_play(t_player *play)
{
	int				index;

	index = 0;
	while (play)
	{
		printf("\nN*[%d]\nName[%s]\nCom[%s]\nCodeSize[%d]\nCode[",
				play->id, play->name, play->comment, play->code_size);
		ft_print_octet(play->code, play->code_size);
		printf("]\n");
		play = play->next;
	}
}
