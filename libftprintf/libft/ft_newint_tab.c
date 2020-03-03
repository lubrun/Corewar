/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newint_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:51:40 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:38 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_newint_tab(int size, int value)
{
	int		*tab;
	int		index;

	if (!(tab = ft_memalloc(sizeof(int) * size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		tab[index] = value;
		index++;
	}
	return (tab);
}
