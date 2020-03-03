/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:33:34 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:52:04 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_2dinsert(void **tab, void *value, size_t size)
{
	void	**fresh_tab;
	int		len;
	int		index;

	len = ft_tablen(tab);
	if (!(fresh_tab = ft_memalloc(size * (len + 2))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		fresh_tab[index] = tab[index];
		index++;
	}
	fresh_tab[index++] = value;
	fresh_tab[index] = NULL;
	free(tab);
	return (fresh_tab);
}
