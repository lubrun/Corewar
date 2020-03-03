/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:59:34 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 19:47:52 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_inttablen(int *tab, int limit)
{
	size_t len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len] && tab[len] != limit)
		len++;
	return (len);
}
