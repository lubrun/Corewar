/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:17:02 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:07 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*rtn;

	if (!(rtn = (unsigned char *)malloc(size)))
		return (NULL);
	ft_bzero((char *)rtn, size);
	return (rtn);
}
