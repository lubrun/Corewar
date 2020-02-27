/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:25:19 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/27 17:16:48 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_free_chariot(t_chariot *pc)
{
	pc->next = NULL;
	pc->start = NULL;
	free(pc->r);
	free(pc);
}

void		ft_free_pc(t_chariot *pc)
{
	if (pc && pc->next)
		ft_free_pc(pc->next);
	if (pc)
	{
		free(pc->r);
		free(pc);
	}
}

void		ft_free_player(t_player *play)
{
	if (play && play->next)
		ft_free_player(play->next);
	if (play)
	{
		free(play->name);
		free(play->comment);
		free(play->code);
		free(play);
	}
}

void		ft_free_info(t_info *info)
{
	if (info)
	{
		if (info->map)
			free(info->map);
		if (info->preset_player)
			free(info->preset_player);
		if (info->line)
			free(info->line);
		if (info->intline)
			free(info->intline);
		free(info);
	}
}

void		ft_free_all(t_info *info)
{
	if (info)
	{
		ft_free_pc(info->chariot);
		ft_free_player(info->play);
		ft_free_info(info);
	}
}
