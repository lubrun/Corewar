/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dcontains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:00:25 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:52:13 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_2dcontains(char **tab, char *elem)
{
	int		index;

	index = 0;
	while (tab[index])
	{
		if (ft_strcmp(tab[index], elem) == 0)
			return (1);
		index++;
	}
	return (0);
}
