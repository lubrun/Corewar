/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:27:05 by lelajour          #+#    #+#             */
/*   Updated: 2020/02/29 20:46:35 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

unsigned int	ft_unsigned_atoi(char *line)
{
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	while (line[i] >= 48 && line[i] <= 57)
		num = (num * 10) + (line[i++] - '0');
	return ((unsigned int)num);
}

unsigned int	get_number_verbose(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
			return (ft_unsigned_atoi(&line[i]));
		i++;
	}
	return (0);
}

short			check_bit(unsigned int var, short pos)
{
	return (var & (1 << pos));
}

char			*ft_find_player_name(int player, t_info *info)
{
	int			i;
	t_player	*tmp;

	i = 0;
	tmp = info->play;
	while (++i < player)
		tmp = tmp->next;
	return (tmp->name);
}
