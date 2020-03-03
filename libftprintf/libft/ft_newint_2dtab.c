/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newint_2dtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:48:12 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:36 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_newint_2dtab(int x, int y, int value)
{
	int **tab;
	int index;

	if (!(tab = ft_memalloc(sizeof(int *) * y)))
		return (NULL);
	index = 0;
	while (index < y)
	{
		tab[index] = ft_newint_tab(x, value);
		index++;
	}
	return (tab);
}
