/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 14:12:32 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 17:03:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/coreware.h"

/*
**		Check depuis start que les 4 prochains octets soient null.
*/

int			ft_check_null(int *tab, int start, int end)
{
	int	index;

	index = start;
	while (index < end)
	{
		if (tab[index] != 0)
			return (0);
		index++;
	}
	return (1);
}

/*
**	depuis le 140 octet et pendant 2048(COMMENT_LENGTH)octets check comment 
**	(140 -> 2188)
*/

int			ft_check_comment(int *tab, t_player *play)
{
	int	index;
	int	count;
	int	max;

	count = 0;
	index = PROG_NAME_LENGTH + 12;
	max = index + COMMENT_LENGTH;
	while (index < max)
	{
		if (tab[index])
			count++;
		index++;
	}
	if (!(play->comment = malloc(sizeof(char *) * (count + 1))))
		return (0);
	index = PROG_NAME_LENGTH + 12;
	while (tab[index] && index < max)
	{
		play->comment[index - (PROG_NAME_LENGTH + 12)] = tab[index];
		index++;
	}
	play->comment[index - (PROG_NAME_LENGTH + 12)] = '\0';
	if (!ft_check_null(tab, index,(16 + PROG_NAME_LENGTH + COMMENT_LENGTH)))
		return (ft_error(0, "REWRITING IN COMMENT\n"));
	printf("Comment [%s]\n", play->comment);
	return (1);
}

/*
**	check les 4 octets nulls(132->136) + les 4 octets suivant (136->140)
**	contenant la size du code
*/

int			ft_check_code_size(int *tab, t_player *play)
{
	int	index;
	int	max;
	int	exposant;

	exposant =	16777216;
	index = 8 + PROG_NAME_LENGTH;
	max = index + 4;
	while (index < max)
	{
		play->code_size += (tab[index] * exposant);
		index++;
		exposant = (exposant / 256);
	}
	printf("SIZE == [%d]\n",play->code_size);
	if (play->code_size > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}

/*
**	CHECK LE NAME SUR LES 128(=PROG_NAME_LONG) PROCHAINS OCTETS DONC DE 4 a 132.
*/

int			ft_check_name(int *tab, t_player *play)
{
	int	index;
	int	max;
	int	count;

	count = 0;
	index = 4;
	max = PROG_NAME_LENGTH + index;
	while (index < max)
	{
		if (tab[index])
			count++;
		index++;
	}
	index = 4;
	printf("count == [%d]\n", count);
	if (!(play->name = malloc(sizeof(char*) * (count + 1))))
			return (ft_error(0, "ERROR MALLOC NAME\n"));
	while (tab[index] && index < max)
	{
		play->name[index - 4] = tab[index];
		index++;
	}
	play->name[index - 4] = '\0';
	printf("play->name == [%s]\n", play->name);//
	if (!play->name || !ft_check_null(tab, index, (8 + PROG_NAME_LENGTH)))
		return (ft_error(0, "NO NAME || REWRITE IN NAME\n"));
	return (1);
}

/*
**	HEADER DE 4 OCTETS CHECK COREWAR_EXEC_MAGIC
*/

int			ft_check_header(char *str)
{
	int index;

	index = 0;
	while (str[index] == '0')
		index++;
	if (!ft_strncmp(&str[index], ft_lltoa_base(COREWAR_EXEC_MAGIC, 16),
				(8 - index)))
		return (1);
	else
		return (ft_error(0, "ERROR MAGIC CODE"));
}

int			ft_parsing(t_info *info)
{
	t_player *player;

	player = NULL;
	player = ft_new_player(player);
	if (!ft_check_header(info->line) ||
			!ft_check_name(info->intline, player) || 
			!ft_check_code_size(info->intline, player) ||
			!ft_check_comment(info->intline, player))
		return (ft_error(0, "FT_PARSING ERROR\n"));
	info->play = player;
	ft_parsing_code(info, player);
	return (1);
}
