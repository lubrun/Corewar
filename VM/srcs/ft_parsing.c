/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:55 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 17:17:19 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
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
	if (!(play->comment = ft_memalloc(sizeof(char *) * (count + 1))))
		return (0);
	index = PROG_NAME_LENGTH + 12;
	while (tab[index] && index < max)
	{
		play->comment[index - (PROG_NAME_LENGTH + 12)] = tab[index];
		index++;
	}
	play->comment[index - (PROG_NAME_LENGTH + 12)] = '\0';
	if (!ft_check_null(tab, index, (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)))
		return (ft_error(0, "REWRITING IN COMMENT\n"));
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
	if (!(play->name = ft_memalloc(sizeof(char*) * (count + 1))))
		return (ft_error(0, "ERROR MALLOC NAME\n"));
	while (tab[index] && index < max)
	{
		play->name[index - 4] = tab[index];
		index++;
	}
	play->name[index - 4] = '\0';
	if (!play->name || !ft_check_null(tab, index, (8 + PROG_NAME_LENGTH)))
		return (ft_error(0, "NO NAME || REWRITE IN NAME\n"));
	return (1);
}

/*
**	HEADER DE 4 OCTETS CHECK COREWAR_EXEC_MAGIC
*/

int			ft_check_header(char *str)
{
	int		index;
	char	*lltoa;

	lltoa = ft_lltoa_base(COREWAR_EXEC_MAGIC, 16);
	index = 0;
	while (str[index] == '0')
		index++;
	if (!ft_strncmp(&str[index], lltoa, (8 - index)) &&
			(int)ft_strlen(lltoa) == (8 - index))
	{
		free(lltoa);
		return (1);
	}
	free(lltoa);
	return (ft_error(0, "ERROR MAGIC CODE"));
}

int			ft_parsing(t_info *info, int num)
{
	t_player *player;

	player = NULL;
	player = ft_new_player(player);
	player->id = num;
	if (!ft_check_header(info->line) ||
			!ft_check_name(info->intline, player) ||
			!ft_check_code_size(info->intline, player) ||
			!ft_check_comment(info->intline, player))
		return (ft_error(0, "FT_PARSING ERROR\n"));
	ft_addplayer(&info->play, player);
	ft_parsing_code(info, player);
	return (1);
}
